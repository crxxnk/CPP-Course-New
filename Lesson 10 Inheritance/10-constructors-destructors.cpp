#include <iostream>

/*
! Constructors and destructors
? A Derived class inherits from its Base class
! The Base part of the Derived class MUST be initialized BEFORE the Derived class is initialized
? When a Derived object is created
  * Base class constructor executes, then
  * Derived class constructor executes
* For example:

class Base {
public:
  Base() { std::cout << "Base constructor" << std::endl; }
};

class Derived : public Base {
public:
  Derived() { std::cout << "Derived constructor" << std::endl; }
};

Base base; //! Output: Base constructor
Derived derived; //! Output: Base constructor, Derived constructor

? Class destructors are invoked in the reverse order as constructors
! The Derived part of the Derived class MUST be destroyed BEFORE the Base class destructor is invoked
? When a Derived object is destroyed
  * Derived class destructor executes, then
  * Base class destructor executes
  * Each destructor should free resources allocated in it's own constructors
* For example:

class Base {
public:
  Base() { std::cout << "Base constructor" << std::endl; }
  ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
  Derived() { std::cout << "Derived constructor" << std::endl; }
  ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

Base base; //! Output: Base constructor, Base destructor
Derived derived; //! Output: Base constructor, Derived constructor, Derived destructor, Base destructor

! A Derived class does NOT inherit
  * Base class constructors
  * Base class destructor
  * Base class overloaded assignment operators
  * Base class friend functions
? However, the derived class constructors, destructors and overloaded assignment operators can invoke the base-class versions
? C++11 allows explicit inheritance of base 'non-special' constructors with
  * 'using Base::Base;' anywhere in the derived class declaration
  * Lots of rules involved, often better to define constructors yourself
*/

class Base
{
private:
  int value;
public:
  Base(): value(0) { std::cout << "Base no-args constructor" << std::endl; }
  Base(int x): value(x) { std::cout << "Base (int) overloaded constructor" << std::endl; }
  ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base
{
  // using Base::Base; uses the base overloaded constructor instead of the derived one
private:
  int doubledValue;
public:
  Derived(): doubledValue(10) { std::cout << "Derived no-args constructor" << std::endl; }
  Derived(int x): doubledValue(x*2) { std::cout << "Derived (int) overloaded constructor" << std::endl; }
  ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main()
{
  // Base b;
  // Base b{100};
  // Derived d;
  Derived d {100};


  return 0;
}