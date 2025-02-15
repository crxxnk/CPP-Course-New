#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator> // for std::advance

/*
! std::list and std::forward_list
? Sequence containers
? Non-contiguous in memory
? No direct access to elements
? Very efficient for inserting and deleting elements once an element is found

#include <list>
? Dynamic size
  * Lists of elements
  * list is bidirectional (doubly-linked)
! Direct element access is NOT provided
? Rapid insertion and deletion of elements anywhere in the container (constant time)
? All iterators available and invalidate when corresponding element is deleted

std::list<int> l{1,2,3};
1->2->3
1<-2<-3

* std::list - initialization and assignment
std::list<int> l {1,2,3,4,5};
std::list<int> 11(10,100); // ten 100s

std::list<std::string> stooges {
  std::string{"Larry"},
  "Moe",
  std::string{"Curly"}
};

l = {2,4,6,8,10};

* std::list - common methods
std::list<int> l {1,2,3,4,5};
std::cout << l.size(); // 5
std::cout << l.max_size(); // a very large number

std::cout << l.front(); // 1
std::cout << l.back(); // 5

Person p1 {"Larry", 18};
std::list<Person> 1;

l.push_back(p1);
l.pop_back();

l.push_front(Person{"Larry", 18});
l.pop_front;

l.emplace_back("Larry", 18);
l.emplace_front("Moe", 24);

* std::list - methods that use iterators
std::list<int> l {1,2,3,4,5};
auto it = std::find(l.begin(), l.end(), 3);
l.insert(it, 10); // 1 2 10 3 4 5
l.erase(it); // erases the 3, 1 2 10 4 5
l.resize(2); // 1 2
l.resize(5); // 1 2 0 0 0

* Traversing the list(bi-directional)
std::list<int> l {1,2,3,4,5};
auto it = std::find(l.begin(), l.end(), 3);
std::cout << *it; // 2
it++;
std::cout << *it; // 4 points to the next element
it--;
std::cout << *it; // 2 points to the previous element

! std::forward_list
#include <forward_list>
? Dynamic size
  * Lists of elements
  * list is uni-directional (singly-linked)
  * Less overhead than a std::list
! Direct element access is NOT provided
? Rapid insertion and deletion of elements anywhere in the container (constant time)
? Reverse iterators not available. Iterators invalidate when corresponding element is deleted

std::forward_list<int> l {1,2,3};
1->2->3

* std::forward_list - common methods
std::forward_list<int> l {1,2,3,4,5};

std::cout << l.size(); //! Not available
std::cout << l.max_size; // a very large number

std::cout << l.front(); // 1
std::cout << l.back(); //! Not available

Person p1 {"Larry", 18};
std::forward_list<Person> 1;

l.push_front(p1);
l.pop_front;

l.emplace_front("Moe", 24);

* std::forward_list - methods that use iterators
std::forward_list<int> l {1,2,3,4,5};
auto it = std::find(l.begin(), l.end(), 3);
l.insert_after(it, 10); // 1 2 3 10 4 5
l.emplace_after(it, 100); // 1 2 3 100 10 4 5
l.erase_after(it); // erases 100, 1 2 3 10 4 5
l.resize(2); // 1 2
l.resize(5) // 1 2 0 0 0
*/

class Person {
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;
public:
  Person() : name("Unknown"), age(0) {}
  Person(std::string name, int age) : name(name), age(age) {}
  bool operator<(const Person &rhs) const {
    return this->age < rhs.age;
  }
  bool operator==(const Person &rhs) const {
    return this->age == rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name << " " << p.age;
  return os;
}

template <typename T>
void display(const std::list<T> &l) {
  std::cout << "[ ";
  for(const auto & elem : l)
    std::cout << elem << " ";
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "\nTest 1 ==============================\n" << std::endl;

  std::list<int> l1 {1,2,3,4,5};
  display(l1);

  std::list<std::string> l2;
  l2.push_back("Back");
  l2.push_front("Front");
  display(l2);

  std::list<int> l3;
  l3 = {1,2,3,4,5,6,7,8,9,10};
  display(l3);

  std::list<int> l4(10, 100);
  display(l4);
}

void test2() {
  std::cout << "\nTest 2 ==============================\n" << std::endl;

  std::list<int> l {1,2,3,4,5,6,7,8,9,10};
  display(l);
  std::cout << "Size: " << l.size() << std::endl;
  std::cout << "Front: " << l.front() << std::endl;
  std::cout << "Back: " << l.back() << std::endl;

  l.clear();
  display(l);
  std::cout << "Size: " << l.size() << std::endl;
}

void test3() {
  std::cout << "\nTest 3 ==============================\n" << std::endl;

  std::list<int> l {1,2,3,4,5,6,7,8,9,10};
  display(l);

  l.resize(5);
  display(l);

  l.resize(10);
  display(l);

  std::list<Person> people;
  people.resize(5);
  display(people);
}

void test4() {
  std::cout << "\nTest 4 ==============================\n" << std::endl;

  std::list<int> l {1,2,3,4,5,6,7,8,9,10};
  display(l);
  auto it = std::find(l.begin(), l.end(), 5);
  if(it != l.end())
    l.insert(it, 100); // inserts 100 before it
  display(l);

  std::list <int> l2 {1000, 2000, 3000};
  l.insert(it, l2.begin(), l2.end()); // inserts l2 before it
  display(l);

  std::advance(it, -4); // point to the 100
  std::cout << *it << std::endl;

  l.erase(it); // remove the 100 - iterator becomes invalid
  display(l);
}

void test5() {
  std::cout << "\nTest 5 ==============================\n" << std::endl;
  
  std::list<Person> friends {
    {"Rita", 15},
    {"Alex", 16},
    {"Maria", 18}
  };

  display(friends);
  std::string name;
  int age;
  std::cout << "Enter the name of the next friend: ";
  getline(std::cin, name);
  std::cout << "Enter their age: ";
  std::cin >> age;
  
  friends.emplace_back(name, age);
  display(friends);

  auto it = std::find(friends.begin(), friends.end(), Person("Alex", 16));
  if(it != friends.end())
    friends.emplace(it, "Frank", 23); // Insert Frank before Alex
  display(friends);
}

void test6() {
  std::cout << "\nTest 6 ==============================\n" << std::endl;

  std::list<Person> stooges {
    {"Larry", 18},
    {"Moe", 25},
    {"Curly", 17}
  };

  display(stooges);
  stooges.sort();
  display(stooges);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}