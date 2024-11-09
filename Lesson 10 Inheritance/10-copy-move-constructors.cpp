#include <iostream>

/*
! Copy/Move constructors and overloaded operator=
? Not inherited from the Base class
? You may not need to provide your own
  * Compiler-provided versions may be just fine
? We can explicitly invoke the Base class versions from the Derived class

! Copy constructor
? Can invoke Base copy constructor explicitly
  * Derived object 'other' will be sliced

Derived::Derived(const Derived &other): Base(other), { Derived initialization list }
{
  code
}
*/

struct Base // made them structs just for fun
{
  int value;
  Base(): value(0) { std::cout << "Base no-args constructor" << std::endl; }
  Base(int x): value(x) { std::cout << "int Base constructor" << std::endl; }
  Base(const Base &other): value(other.value) { std::cout << "Base copy constructor" << std::endl; }
  Base &operator=(const Base &rhs) {
    if(this != &rhs)
      value = rhs.value;
    return *this;
  }
};

struct Derived : public Base
{
  int doubled_value;
  Derived(): Base(), doubled_value(0) { std::cout << "Derived no-args constructor" << std::endl; }
  Derived(int x): Base(x), doubled_value(x*2) { std::cout << "int Derived constructor" << std::endl; }
  Derived(const Derived &other): Base(other), doubled_value(other.doubled_value) { std::cout << "Derived copy constructor" << std::endl; }
  Derived &operator=(const Derived &rhs) {
    if(this != &rhs) {
      Base::operator=(rhs);
      doubled_value = rhs.doubled_value;
    }
    return *this;
  }
};

int main()
{
  Base alex(15);
  Base rita(alex);
  Derived gor(30);
  Derived nick(gor);

  std::cout << rita.value << std::endl;
  std::cout << gor.value << std::endl;
}