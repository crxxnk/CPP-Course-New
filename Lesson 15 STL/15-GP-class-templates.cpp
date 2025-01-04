/*
! Generic Programming with class templates
? What is a C++ Class Template?
* Similar to function template, but at class level
* Allows plugging-in any data type
* Compiler generates the appropriate class from the blueprint

? Let's say we want a class to hold items where the item has a name and an value
class Item
{
private:
  std::string name;
  int value;
public:
  Item(std::string name, int value): name(name), value(value) {}
  std::string getName() const { return name; }
  int getValue() const { return value; }
};

* But we'd like our Item class to be able to hold any type of data in addition to the string
* We can't overload class names
* We don't want to use dynamic polymorphism

class Item
{
private:
  std::string name;
  T value;
public:
  Item(std::string name, T value): name(name), value(value) {}
  std::string getName() const { return name; }
  T getValue() const { return value; }
};
*/