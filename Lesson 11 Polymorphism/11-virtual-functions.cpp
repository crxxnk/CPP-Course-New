#include <iostream>
#include <vector>

/*
! Virtual functions
* Redefined functions are bound statically
* Overriden functions are bound dynamically
* Virtual functions are overriden
* Allow us to treat all objects generally as objects of the Base class

? Declaring virtual functions
* Declare the function you want to override as virtual in the Base class
* Virtual functions are virtual all the way down the hierarchy from this point
* Dynamic polymorphism only via Account class pointer or reference
class Account {
public:
  virtual void withdraw(double amount);
  ...
}
* Override the function in the Derived classes
* Function signature and return type must match EXACTLY
* Virtual keyword not required but is best practice
* If you don't provide an overriden version it is inherited from its base class
class Checking : public Account {
public:
  (virtual) void withdraw(double amount);
  ...
}
*/

class Account
{
public:
  virtual void withdraw(double amount) { std::cout << "In Account::withdraw" << std::endl; }
  virtual ~Account() { std::cout << "Destructor for Account" << std::endl; }
};

class Savings : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Savings::withdraw" << std::endl; }
  ~Savings() { std::cout << "Destructor for Savings" << std::endl; }
};

class Checking : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Checking::withdraw" << std::endl; }
  ~Checking() { std::cout << "Destructor for Checking" << std::endl; }
};

class Trust : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Trust::withdraw" << std::endl; }
  ~Trust() { std::cout << "Destructor for Trust" << std::endl; }
};

/*
! Virtual Destructors
* Problems can occur when we destroy polymorphic objects
! If a derived class is destroyed by deleting its storage via the base class pointer
! and the class doesn't have a virtual destructor, then the behavior is undefined in the C++ standard
* Derived objects must be destroyed in the correct order starting at the correct destructor
? Solution/Rule:
  * If a class has virtual functions
  * ALWAYS provide a public virtual destructor
  * If base class destructor is virtual then all derived class destructors are also virtual
class Account {
public:
  virtual void withdraw(double amount);
  virtual ~Account();
  ...
};
*/

int main()
{
  // Virtual functions section
  std::cout << "==== Pointers ====" << std::endl;
  Account* p1 = new Account;
  Account* p2 = new Savings;
  Account* p3 = new Checking;
  Account* p4 = new Trust;

  p1->withdraw(1000);
  p2->withdraw(1000);
  p3->withdraw(1000);
  p4->withdraw(1000);

  std::cout << "==== Array ====" << std::endl;
  Account* accArray[] = {p1, p2, p3, p4};
  for(size_t i = 0; i < 4; i++)
    accArray[i]->withdraw(1000);

  std::cout << "==== Vector ====" << std::endl;
  std::vector<Account*> accounts = {p1, p2, p3, p4};
  for(auto acc: accounts)
    acc->withdraw(1000);

  delete p1;
  delete p2;
  delete p3;
  delete p4;
  // Virtual functions section

  return 0;
}