#include <iostream>
#include <memory>
#include <vector>
#include "Account.h"
/*
! The unique_ptr
* Simple smart pointer - very efficient
? unique_ptr<T>
  * Points to an object of type T on the heap
  * It is unique - there can only be one unique_ptr<T> pointing to the object on the heap
  * Owns what it points to
  * Cannot be assigned or copied
  * CAN be moved
  * When the pointer is destroyed, what it points to is automatically destroyed

std::unique_ptr<int> p1 {new int {100}};
std::cout << *p1 << std::endl; // 100
. *p1 = 200;
std::cout << *p1 << std::endl; // 200
* Automatically deleted

* unique_ptr - some other useful methods
std::unique_ptr<int> p1 {new int {100}};
std::cout << p1.get() << std::endl; // 0x564388 (memory address)
p1.reset(); // p1 is now nullptr
if(p1)
  std::cout << *p1 << std::endl; // won't execute because it's a nullptr
* Automatically deleted

* unique_ptr - user defined classes
std::unique_ptr<Account> p1 {new Account{"Larry"}};
std::cout << *p1 << std::endl;
p1->deposit(1000);
p1->withdraw(500);
* Automatically deleted

* unique_ptr - vectors and move
std::vector<std::unique_ptr<int>> vec;
std::unique_ptr<int> ptr {new int{100}};
vec.push_back(ptr); //! Error - copy not allowed
vec.push_back(std::move(ptr));
* Automatically deleted

* unique_ptr - make_unique(best way to initialize unique pointers)
std::unique_ptr<int> = make_unique<int>(100);
std::unique_ptr<Account> p2 = make_unique<Account>("Curly", 5000);
auto p3 = make_unique<Player>("Hero", 100, 100);
* Automatically deleted
? More efficient - no calls to new or delete
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

int main()
{
  // Test *t1 = new Test{1000}; We need to call delete
  std::unique_ptr<Test> t1 = std::make_unique<Test>(1000); // We don't need to call delete
  std::unique_ptr<Test> t2;
  t2 = std::move(t1);
  if(!t1)
    std::cout << "t1 is a nullptr" << std::endl;
  
  std::unique_ptr<Account> a1 = std::make_unique<Savings>("Alex", 5000);
  std::unique_ptr<Account> a2 = std::make_unique<Trust>("Rita", 10000);

  std::cout << *a1 << std::endl;
  std::cout << *a2 << std::endl;

  std::vector<std::unique_ptr<Account>> accounts;
  accounts.push_back(std::make_unique<Checking>("James", 1000));
  accounts.push_back(std::make_unique<Savings>("Billy", 2500));
  accounts.push_back(std::make_unique<Trust>("Bobby", 5000));

  for(auto &acc : accounts)
    std::cout << *acc << std::endl;

  return 0;
}