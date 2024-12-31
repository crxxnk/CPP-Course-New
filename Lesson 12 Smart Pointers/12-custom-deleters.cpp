#include <iostream>
#include <memory>

/*
! Custom deleters (rarely used)
* Sometimes when we destroy a smart pointer we need more than to just destroy the object on the heap
* These are special use-cases
* C++ smart pointers allow you to provide custom deleters
? Lots of way to achieve this
  * Functions
  * Lambdas
  * Others...

? Custom deleters - function
void myDeleter(Some_Class* raw_ptr) {
  *custom deleter code
  delete raw_ptr;
}

shared_ptr<Some_Class> ptr {new Some_Class{}, myDeleter};

? Custom deleters - lambda (will see later in the course)
shared_ptr<Test> ptr (new Test{100}, [] (Test* ptr)) {
  std::cout << "Using my custom deleter" << std::endl;
  delete ptr;
});
*/

class Test
{
private:
  int data;
public:
  Test(): data(0) { std::cout << "Test contructor (" << data << ")" << std::endl;}
  Test(int data): data(data) { std::cout << "Test contructor (" << data << ")" << std::endl;}
  int get_data() const { return data; }
  ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test* ptr) {
  std::cout << "Using my custom function deleter" << std::endl;
  delete ptr;
}

int main()
{
  {
    std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter};
  }

  {
    std::shared_ptr<Test> ptr2 (new Test{500}, [] (Test* ptr) {
      std::cout << "Using my custom lambda deleter" << std::endl;
      delete ptr;
    });
  }

  return 0;
}