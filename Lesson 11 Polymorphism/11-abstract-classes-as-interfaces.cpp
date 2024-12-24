#include <iostream>
#include <ostream>

/*
! Abstract classes as interfaces
? What is using a class as an interface?
* An abstract class that has only pure virtual functions
* These functions provide a general set of services to the user of the class
* Provided as public
* Each subclass is free to implement these services as needed
* Every service(method) must be implemented
* The service type information is strictly enforced

* C++ does not provide true interfaces
* We use abstract classes and pure virtual functions to achieve it
* Suppose we want to be able to provide Printable support for any object we wish without knowing its implementation at compile time
std::cout << any_object << std::endl;
* any_object must conform to the Printable interface

class Printable
{
  friend ostream &operator<<(ostream&, const Printable& obj);
public:
  virtual void print(ostream &os) const = 0;
  virtual ~Printable() {}
  ...
};

ostream &operator<<(ostream&, const Printable& obj) {
  obj.print(os);
  return os;
}

class Any_Class : public Printable
{
public:
  ! Must override Printable::print()
  void print(ostream &os) override {
    os << "Hi from Any_Class" << std::endl;
  }
};

Any_Class *ptr = new Any_Class;
std::cout << *ptr << std::endl;

void func(Any_Class &obj) {
  std::cout << obj << std::endl;
}

void func2(Printable &obj) {
  std::cout << obj << std::endl;
}
func1(*ptr); // "Hi from Any_Class"
func2(*ptr); // "Hi from Any_Class"
*/

class I_Printable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() = default;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Account : public I_Printable
{
public:
  virtual void withdraw(double amount) { std::cout << "In Account::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Account display"; }
  virtual ~Account() {}
};

class Checking : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Checking::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Checking display"; }
  ~Checking() {}
};

class Savings : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Savings::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Savings display"; }
  ~Savings() {}
};

class Trust : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Trust::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Trust display"; }
  ~Trust() {}
};

class Dog : public I_Printable
{
public:
  void print(std::ostream &os) const override { os << "Woof Woof"; }
};

void print(const I_Printable &obj) {
  std::cout << obj << std::endl;
}

int main()
{
  Dog *dog = new Dog;
  std::cout << *dog << std::endl;

  print(*dog);

  Account* p1 = new Account;
  std::cout << *p1 << std::endl;

  Account* p2 = new Checking;
  std::cout << *p2 << std::endl;

  return 0;
}