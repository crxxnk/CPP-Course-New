#include <iostream>

/*
! Protected Members and Class Access
? Protected class member modifier

class Base {
protected:
  // protected Base class members...
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
// protected: a
// protected: b
// c: no access
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
// private: a
// private: b
// c: no access
};
*/

class Base
{
public:
  int a = 0;
  void display() { std::cout << a << ", " << b << ","};
};

int main()
{

  return 0;
}