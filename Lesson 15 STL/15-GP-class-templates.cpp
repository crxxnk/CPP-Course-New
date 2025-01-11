#include <iostream>
#include <vector>

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

template <typename T>
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

Item<int> item1 {"Alex", 1};
Item<double> item1 {"Rita", 1000.0};
Item<std::string> item3 {"Frank", "Boss"};

std::vector<Item<int>> vec;

* We can have multiple template parameters
* And their types can be different

template <typename T1, typename T2>
struct MyPair {
  T1 first;
  T2 second;
};

MyPair<std::string, int> p1 {"Alex", 100};
MyPair<int, double> p2 {124, 13.6};
std::vector<MyPair<int, double>> vec;

* std::pair
#include <utility>

std::pair<std::string, int> p1 {"Alex", 100};
std::cout << p1.first << std::endl; // Alex
std::cout << p1.second << std::endl; // 100
*/

template <typename T>
class Item {
private:
  std::string name;
  T value;
public:
  Item(std::string name, T value): name(name), value(value) {}
  std::string getName() const { return name; }
  T getValue() const { return value; }
};

template <typename T1, typename T2>
struct MyPair {
  T1 first;
  T2 second;
};

int main()
{
  Item<int> item1 {"Alex", 100};
  std::cout << item1.getName() << " " << item1.getValue() << std::endl;

  Item<std::string> item2 {"Alex", "Daddy"};
  std::cout << item2.getName() << " " << item2.getValue() << std::endl;

  Item<Item<std::string>> item3 {"Alex", {"C++", "Daddy"}};
  std::cout << item3.getName() << " " << item3.getValue().getName() << " " << item3.getValue().getValue() << std::endl;

  std::vector<Item<double>> vec;
  vec.push_back(Item<double>("Larry", 100.0));
  Item<double>* item = new Item<double>("Alex", 200.0);
  vec.push_back(*item);
  vec.push_back(Item<double>("Rita", 300.0));

  for(const auto &item : vec)
    std::cout << item.getName() << " " << item.getValue() << std::endl;
  
  MyPair<std::string, int> p1 {"Rita", 100};
  MyPair<int, double> p2 {124, 13.6};
  std::cout << p1.first << ", " << p1.second << std::endl;
  std::cout << p2.first << ", " << p2.second << std::endl;

  delete item;

  return 0;
}