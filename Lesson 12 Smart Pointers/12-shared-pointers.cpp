#include <memory>
#include <iostream>
#include <vector>
#include "Account.h"

/*
! The shared_ptr
* Provides shared ownership of heap objects
? shared_ptr<T>
  * Points to an object of type T on the heap
  * It is not unique - there can be many shared_ptrs pointing to the same object on the heap
  * Establishes shared ownership relationship
  * CAN be assigned and copied
  * CAN be moved
  * Doesn't support managing arrays by default
  * When the use count is zero, the managed object on the heap is destroyed

std::shared_ptr<int> p1 {new int {100}};
std::cout << *p1 << std::endl; // 100
. *p1 = 200;
std::cout << *p1 << std::endl; // 200
* Automatically deleted

* use_count - the number of shared_ptr objects managing the heap object
std::shared_ptr<int> p1 {new int{100}};
std::cout << p1.use_count() << std::endl;

std::shared_ptr<int> p2 = p1;
std::cout << p1.use_count() << std::endl;

p1.reset(); //* decrement the use_count; p1 is nulled out
std::cout << p1.use_count() << std::endl;
std::cout << p2.use_count() << std::endl;
* Automatically deleted

std::shared_ptr<Account> p1 {new Account{"Larry"}};
std::cout << *p1 << std::endl;

p1->deposit(1000);
p1->withdraw(500);
* Automatically deleted

std::vector<std::shared_ptr<int>> vec;
std::shared_ptr<int> ptr{new int{100}};
vec.push_back(ptr); //! OK - copy IS allowed
std::cout << ptr.use_count() << std::endl; // 2
* Automatically deleted

* shared_ptr - make_shared (best way to initialize shared pointers)
std::shared_ptr<int> p1 = std::make_shared<int>(100);
std::shared_ptr<int> p2 = p1;
std::shared_ptr<int> p3;
p3 = std::make_shared<int>(50);
* Automatically deleted
? std::make_shared is more efficient
! All 3 pointers point to the SAME object on the heap!
* When the use_count becomes 0 the heap object is deallocated
*/

class Test
{
private:
  int data;
public:
  Test(): data(0) { std::cout << "Test constructor (" << data << ")" << std::endl; }
  Test(int data): data(data) { std::cout << "Test constructor (" << data << ")" << std::endl; }
  int get_data() const { return data; }
  ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

void getUseCount(std::shared_ptr<Test> ptr)
{
  std::cout << "Use count " << ptr.use_count() << std::endl;
}

int main()
{
  std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
  getUseCount(ptr);
  std::cout << "Use count " << ptr.use_count() << std::endl;
  {
    std::shared_ptr<Test> ptr1 = ptr;
    std::cout << "Use count: " << ptr.use_count() << std::endl;
    {
      std::shared_ptr<Test> ptr2 = ptr;
      std::cout << "Use count: " << ptr.use_count() << std::endl;
      ptr.reset();
    }
    std::cout << "Use count: " << ptr.use_count() << std::endl;
  }
  std::cout << "Use count: " << ptr.use_count() << std::endl;

  std::shared_ptr<Account> acc1 = std::make_shared<Account>("Larry", 10000);
  std::shared_ptr<Account> acc2 = std::make_shared<Checking>("Rita", 2);
  std::shared_ptr<Account> acc3 = std::make_shared<Savings>("Alex", 150000);

  std::vector<std::shared_ptr<Account>> accounts;
  accounts.push_back(acc1);
  accounts.push_back(acc2);
  accounts.push_back(acc3);

  for(const auto &acc : accounts) {
    std::cout << *acc << std::endl;
    std::cout << "Use count " << acc.use_count() << std::endl; // 2 because it makes a copy of each account to put in the vector
  }

  return 0;
}