#include <iostream>

/*
! Protected Members and Class Access
? Protected class member modifier

class Base {
protected:
  protected Base class members...
};

* Accessible from the Base class itself
* Accessible from classes Derived from Base
* Not accessible by objects of Base or Derived

* Protected Inheritance:

class Example
{
public:
  int a;
protected:
  int b;
private:
  int c;
};

class Inherited : protected Example
{
protected: a
protected: b
c: no access
};

* Private Inheritance:

class Example
{
public:
  int a;
protected:
  int b;
private:
  int c;
};

class Inherited : private Example
{
private: a
private: b
c: no access
};
*/

class Base
{
public:
  int a = 0;
  void display() { std::cout << a << ", "  << b << ", " << c << std::endl; }
protected:
  int b = 0;
private:
  int c = 0;
};

class Derived : public Base
{
  // a will be public
  // b will be protected
  // c will not be accessible
public:
  void accessBaseMembers(){
    a = 100; // OK
    b = 200; // OK
    //c = 300; //! Compiler Error
  }
};

int main()
{
  std::cout << "=== Base member access from base objects ===============" << std::endl;
  Base base;
  base.a = 100;
  // base.b = 100; //! Compiler Error
  // base.c = 100; //! Compiler Error

  std::cout << "=== Base member access from derived objects ===============" << std::endl;

  Derived d;
  d.a = 100; // OK
  // d.b = 400; //! Compiler Error
  // d.c = 400; //! Compiler Error

  return 0;
}