#include <iostream>

/*
! The override specifier
* We can override Base class virtual functions
* The function signature and return must be EXACTLY the same
* If they are different then we have redefinition NOT overriding
* Redefinition is statically bound
* Overriding is dynamically bound
* C++11 provides an override specifier to have the compiler ensure overriding
class Base {
public:
  virtual void sayHello() const { std::cout << "Hello, I'm a Base object" << std::endl; }
  virtual ~Base() {}
};

class Derived : public Base {
public:
  ! NOT OVERRIDING because I didn't write the const specifier
  virtual void sayHello() { std::cout << "Hello, I'm a Base object" << std::endl; }
  virtual ~Derived() {}
};

class Base {
public:
  virtual void sayHello() const { std::cout << "Hello, I'm a Base object" << std::endl; }
  virtual ~Base() {}
};

class Derived : public Base {
public:
  ! COMPILER ERROR because we didn't make it const but we can easily find the problem now using override
  virtual void sayHello() override { std::cout << "Hello, I'm a Base object" << std::endl; }
  virtual ~Derived() {}
};
*/

class Base
{
public:
  virtual void sayHello() const { std::cout << "Hello, I'm a Base object" << std::endl; }
  virtual ~Base() {}
};

class Derived : public Base {
public:
  /*virtual is optional*/ void sayHello() const override{ std::cout << "Hello, I'm a Derived object" << std::endl; }
  virtual ~Derived() {}
};

/*
! The final specifier
? C++11 provides the final specifier
  * When used at the class level
    * Prevents a class from being derived from
  * When used at method level
    * Prevents virtual method from being overriden in derived classes
  * Used for better compiler optimization
* Class Example:
class My_class final {
  ...
};

class Derived final : public Base{
  ...
};

class Sec_class : public My_class { //! COMPILER ERROR - Can't use final class as base class
  ...
};

* Method example:
class A {
public:
  virtual void doSomething();
};

class B : public A {
  virtual void doSomething() final; // prevent further overriding
};

class C : public B {
  virtual void doSomething(); //! COMPILER ERROR - Can't override
}
*/

int main()
{
  Base* p1 = new Base;
  Base* p2 = new Derived;

  p1->sayHello();
  p2->sayHello();

  delete p1;
  delete p2;

  return 0;
}