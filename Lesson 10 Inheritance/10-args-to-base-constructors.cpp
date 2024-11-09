#include <iostream>

/*
! Passing arguments to base class constructors
? The Base part of a Derived class must be initialized first
? How can we control exactly which Base class constructor is used during initialization?
? We can invoke the whichever Base class constructor we wish in the initialization list of the Derived class

class Base
{
public:
  Base();
  Base(int);
  ...
};

Derived::Derived(int x): Base(x), {optional initializers for Derived}
{
  code
}
*/

struct Base
{
  int value;
  Base(): value(0) { std::cout << "Base no-args constructor" << std::endl; }
  Base(int x): value(x) { std::cout << "int Base constructor" << std::endl; }
};

struct Derived : public Base
{
  int doubled_value;
  Derived(): Base(), doubled_value(0) { std::cout << "Derived no-args constructor" << std::endl; }
  Derived(int x): Base(x), doubled_value(x*2) { std::cout << "int Derived constructor" << std::endl; }
};

int main()
{
  // Base base;
  Base base {100};
  // Derived derived;
  Derived derived {10};
  std::cout << base.value << std::endl;
  std::cout << derived.value << std::endl;
}