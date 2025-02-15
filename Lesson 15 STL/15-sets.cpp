#include <set>
#include <iostream>

/*
! The STL Set containers
? Associative containers
  * Collection of stored objects that allow fast retrieval using a key
  * STL provides Sets and Maps
  * Usually implemented as a balanced binary tree or hashsets
  * Most operations are very efficient
* Sets
  std::set
  std::unordered_set
  std::multiset
  std::unordered_multiset

* std::set
#include <set>
* Similar to a mathematical set
* Ordered by key
* No duplicate elements
* All iterators available and invalidate when corresponding element is deleted

* std::set - initialization and assignment
std::set<int> s {1,2,3,4,5};

std:set<std::string> stooges {
  std::string{"Larry"},
  "Moe",
  std::string{"Curly"}
};

s = {2,4,6,8,10};

* std::set - common methods
std::set<int> s {4,1,1,3,3,2,5} //! 1 2 3 4 5, duplicates are ignored and it's automatically sorted

std::cout << s.size(); // 5
std::cout << s.max_size() // a very large number

* No concept of front and back

s.insert(7); // 1 2 3 4 5 6 7

Person p1 {"Larry", 18};
Person p2 {"Moe", 25};

std::set<Person> stooges;

stooges.insert(p1); // adds p1 to the set
auto result = stooges.insert(p2); // adds p2 to the set
? Uses operator< for ordering
? Returns a std::pair<iterator, bool>
  * first is an iterator to the inserted element or to the duplicate in the set
  * second is a boolean indicating success or failure

std::set<int> s {1,2,3,4,5};

s.erase(3); // erase the 3 : 1 2 4 5

auto it = s.find(5);
if(it != s.end())
  s.erase(it); // erase the 5 : 1 2 4

std::set<int> s {1,2,3,4,5};

int num = s.cound(1) // 0 or 1 (how many times an element appears in a set)

s.clear(); // remove all elements

s.empty(); // true or false

* std::multi_set
#include <set>
* Sorted by key
* Allows duplicate elements
* All iterators are available

* std::unordered_set
#include <unordered_set>
* Elements are unordered
* No duplicate elements allowed
* Elements cannot be modified
  * Must be erased and new element inserted
* No reverse iterators are allowed

* std::unordered_multiset
#include <unordered_set>
* Elements are unordered
* Allows duplicate elements
* No reverse iterators are allowed
*/

class Person {
  friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
  std::string name;
  int age;
public:
  Person(): name("Unknown"), age(0) {}
  Person(std::string name, int age): name(name), age(age) {}
  bool operator<(const Person &rhs) const {
    return this->age < rhs.age;
  }
  bool operator==(const Person &rhs) const {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
  os << rhs.name << ":" << rhs.age;
  return os;
}

template<typename T>
void display(const std::set<T> &l) {
  if(l.empty()) {
    std::cout << "No elements to display!" << std::endl;
    return;
  }
  std::cout << "[";
  auto it = l.begin();
  while(it != l.end()) {
    if(it == --l.end())
      std::cout << *it;
    else
      std::cout << *it << " ";
    it++;
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "\nTest 1 ==============================\n" << std::endl;
  std::set<int> s1 {1,4,3,5,2};
  display(s1);

  s1 = {1,2,3,1,1,2,2,3,3,4,5};

  s1.insert(0);
  s1.insert(10);
  display(s1);

  if(s1.count(10)) // returns 0 or 1 but 0 and 1 can be treated as a bool so we dont write the == operator
    std::cout << "10 is in the set" << std::endl;
  else
    std::cout << "10 is NOT in the set" << std::endl;
  
  auto it = s1.find(5);
  if(it != s1.end())
    std::cout << "Found: " << *it << std::endl;
  
  s1.clear();
}

void test2() {
  std::cout << "\nTest 2 ==============================\n" << std::endl;
  std::set<Person> stooges {
    {"Larry", 1},
    {"Moe", 2},
    {"Curly", 3}
  };
  display(stooges);

  stooges.emplace("Rita", 15);
  display(stooges);

  stooges.emplace("Alex", 15); //! NO -- 15 already exists
  display(stooges);

  auto it = stooges.find(Person{"Moe", 2});
  if(it != stooges.end())
    stooges.erase(it);
  
  display(stooges);

  it = stooges.find(Person("XXXX", 15));
  if(it != stooges.end())
    stooges.erase(it); // Will remove Rita
  display(stooges);
}

void test3() {
  std::cout << "\nTest 3 ==============================\n" << std::endl;

  std::set<std::string> s {"A","C","B"};
  display(s);

  auto result = s.insert("D");
  display(s);

  std::cout << std::boolalpha;
  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "second: " << result.second << std::endl;

  std::cout << std::endl;

  result = s.insert("A");
  display(s);

  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "second: " << result.second << std::endl;
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}