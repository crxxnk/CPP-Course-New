#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

/*
! Iterators
? Allow abstracting an arbitrary container as a sequence of elements
? They are objects that work like pointers by design
? Most container classes can be traversed with iterators

* Iterators must be declared based on the container type they will iterate over
container_type::iterator_type iterator_name;

std::vector<int>::iterator it1;
std::list<std::string>::iterator it2;
std::map<std::string, std::string>::iterator it3;
std::set<char>::iterator it4;

std::vector<int> vec {1,2,3};
vec.begin() // first element
vec.end() // location after last element

std::set<char> suits {'C','H','S','D'};
suits.begin() // first element
suits.end() // location after last element

* Initializing iterators
std::vector<int> vec {1,2,3};
std::vector<int>::iterator it = vec.begin();
* or
auto it = vec.begin();

? Operation           Description                 Type of Iterator
++it                  Pre-increment               All
it++                  Post-increment              All
it = it1              Assignment                  All
⠀*it                  Dereference                 Input and Output
it->                  Arrow operator              Input and Output
it == it1             Comparison for equality     Input
it != it1             Comparison for inequality   Input
--it                  Pre-decrement               Bidirectional
it--                  Post-decrement              Bidirectional
it + i, it += i       Increment and decrement     Random Access
it - i, it -= i
it < it1, it <= it1   Comparison                  Random Access
it > it1, it >= it1

* While loop example
std::vector<int> vec {1,2,3};
std::vector<int>::iterator it = vec.begin();
while(it != vec.end()) {
  std::cout << *it << std::endl;
  it++;
}

* For loop example
std::vector<int> vec {1,2,3};
for(auto it = vec.begin(); it != vec.end(); it++) {
  std::cout << *it << std::endl;
}

* Set example
std::set<char> suits {'C', 'H', 'S', 'D'};
auto it = suits.begin();
while(it != suits.end()) {
  std::cout << *it << std::endl;
  it++;
}

* Reverse iterators
? Last element is the first and first is the last
? ++ moves backward, -- moves forward
std::vector<int> vec {1,2,3};
std::vector<int>::reverse_iterator it = vec.begin();
while(it != vec.end()) {
  std::cout << *it << " ";
  it++;
} // 3 2 1

? Other iterators
begin() and end()
  * iterator

cbegin() and cend()
  * const_iterator

rbegin() and rend()
  * reverse_iterator

crbegin() and crend()
  * const_reverse_iterator
*/

void display(const std::vector<int>&vec) {
  std::cout << "[ ";
  for(auto const &i: vec)
    std::cout << i << " ";
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "=============================================" << std::endl;
  std::vector<int> nums1 {1,2,3,4,5};
  auto it = nums1.begin(); // point to 1
  std::cout << *it << std::endl;
  it++; // point to 2
  std::cout << *it << std::endl;
  it += 2; // point to 4
  std::cout << *it << std::endl;
  it -= 2; // point to 2
  std::cout << *it << std::endl;
  it = nums1.end() - 1; // points to 5
  std::cout << *it << std::endl;
}

void test2() {
  std::cout << "=============================================" << std::endl;
  std::vector<int>nums1 {1,2,3,4,5};

  std::vector<int>::iterator it = nums1.begin();
  while(it != nums1.end()) {
    std::cout << *it << std::endl;
    it++;
  }

  it = nums1.begin();
  while(it != nums1.end()) {
    *it = 0;
    it++;
  }

  display(nums1);
}

void test3() {
  std::cout << "=============================================" << std::endl;
  std::vector<int> nums1 {1,2,3,4,5};

  std::vector<int>::const_iterator it1 = nums1.begin();
  // auto it1 = nums1.cbegin();

  while(it1 != nums1.end()) {
    std::cout << *it1 << std::endl;
    //⠀*it1 = 0; Compiler error - read only
    it1++;
  }
}

void test4() {
  std::vector<int> vec {1,2,3,4};
  auto it1 = vec.rbegin(); // starts at 4
  while(it1 != vec.rend()) {
    std::cout << *it1 << std::endl;
    it1++;
  }

  std::list<std::string> names {"Larry", "Moe", "Curly"};
  auto it2 = names.crbegin(); // starts at Curly
  std::cout << *it2 << std::endl;
  it2++; // points to Moe
  std::cout << *it2 << std::endl;

  std::map<std::string, std::string> favorites {
    {"Alex", "C++"},
    {"Rita", "Python"},
    {"John", "Java"}
  };
  auto it3 = favorites.begin();
  while(it3 != favorites.end()) {
    std::cout << it3->first << ": " << it3->second << std::endl;
    it3++;
  }
}

void test5() {
  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  auto start = vec.begin() + 2;
  auto finish = vec.end() - 3;

  while(start != finish) {
    std::cout << *start << std::endl;
    start++;
  }
}

int main()
{
  test5();

  return 0;
}