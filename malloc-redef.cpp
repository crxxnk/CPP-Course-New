#include <iostream>
#include <Windows.h>

struct Block {
  unsigned int size;
  bool free;
  Block* next;
};

Block* head = nullptr;

void* memalloc(int size) {
  Block* block = head;
  while(block) {
    if(block->size >= size && block->free) {
      block->free = false;
      return (void*)(block + 1); // usable memory (+1 means +sizeof(Block))
    }
    block = block->next; // move to the next block
  }
  Block* mem = (Block*)VirtualAlloc(
    NULL,
    size + sizeof(Block),
    MEM_COMMIT | MEM_RESERVE,
    PAGE_READWRITE
  );

  if(!mem) {
    std::cout << "Memory allocation failed!" << std::endl;
    return nullptr;
  }

  mem->size = size;
  mem->free = false;
  mem->next = nullptr;

  if(!head)
    head = mem;
  else {
    Block* lastBlock = head;
    while(lastBlock->next) {
      lastBlock = lastBlock->next;
    }
    lastBlock->next = mem;
  }
  return (void*)(mem + 1); // usable memory (+1 means +sizeof(Block))
}

void memfree(void* ptr) {
  if(!ptr)
    return;
  Block* mem = (Block*)ptr - 1; // -1 means -sizeof(Block)
  mem->free = true;
  VirtualFree(mem, 0, MEM_RELEASE);
}

void* memrealloc(void* ptr, int size) {
  if(!ptr) {
    return memalloc(size);
  }

  Block* mem = (Block*)ptr - 1;

  if(mem->size >= size) {
    mem->free = false;
    return (void*)(mem + 1); // usable memory (+1 means +sizeof(Block))
  }
  Block* new_mem = (Block*)VirtualAlloc(
    NULL,
    size + sizeof(Block),
    MEM_COMMIT | MEM_RESERVE,
    PAGE_READWRITE
  );

  if (!new_mem) {
    std::cout << "Memory reallocation failed!" << std::endl;
    return nullptr;
  }

  new_mem->size = size;
  new_mem->free = false;
  new_mem->next = nullptr;

  memcpy(new_mem + 1, ptr, mem->size);
  memfree(ptr);
  return (void*)(new_mem + 1);
}

int main() {
  // int* ptr = (int*)memalloc(sizeof(int));
  // *ptr = 66;
  void* ptr = memalloc(sizeof(int));
  int x = 45;
  int y = 40;
  if(ptr) {
    std::cout << "Memory allocated successfully" << " " << ptr << std::endl;
    std::cout << &x << std::endl;
  }
  else
    std::cout << "Memory did not allocate successfully" << std::endl;
  void* old_ptr = ptr;
  void* new_ptr = memrealloc(ptr, sizeof(int));
  if (new_ptr != old_ptr) {
    std::cout << "Memory moved to a new location\n";
  }

  return 0;
}