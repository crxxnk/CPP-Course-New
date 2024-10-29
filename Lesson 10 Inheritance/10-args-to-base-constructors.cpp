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