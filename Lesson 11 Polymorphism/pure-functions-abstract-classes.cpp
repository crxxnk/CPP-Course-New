#include <iostream>

/*
! Abstract class
  * Cannot instantiate objects
  * These classes are used as base classes in inheritance hierarchies
  * Often referred to as Abstract Base Classes
  ? Too generic to create objects from
    * Shape, Employee, Account, Player
  ? Serves as parent to Derived classes that may have objects
  ? Contains at least one pure virtual function

! Concrete class
  * Used to instantiate objects from
  * All their member functions are defined
    * Checking Account, Savings Account
    * Faculty, Staff
    * Enemy, Level Boss

! Pure virtual function
  ? Used to make a class abstract
  ? Specified with "=0" in its declaration
  virtual void function() = 0; // pure virtual function
  ? Typically do not provide implementations
  ! Derived classes MUST override the base class
  * If the Derived class does not override then the Derived class is also abstract
  * Used when it doesn't make sense for a base class to have an implementation
    * But concrete classes must implement it
  virtual void draw() = 0; // Shape
  virtual void defend() = 0; // Player
*/

int main()
{
  

  return 0;
}