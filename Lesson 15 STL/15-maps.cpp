#include <iostream>
#include <map>
#include <set>

/*
! The STL Set containers
? Associative containers
  * Collection of stored objects that allow fast retrieval using a key
  * STL provides Sets and Maps
  * Usually implemented as a balanced binary tree or hashsets
  * Most operations are very efficient
* Maps
  ! Maps consist of std::pair objects
  std::map
  std::unordered_map
  std::multimap
  std::unordered_multimap

* std::map
#include <map>
* Similar to a dictionary
* Elements are stored as Key, Value pairs(std::pair)
* Ordered by key
* No duplicate elements(keys are unique)
* Direct element access using the key
* All iterators available and invalidate when corresponding element is deleted

* std::map - initialization and assignment
std::map<std::string, int> m1 {
  {"Larry", 18},
  {"Moe", 25}
};

std::map<std::string, std::string> m2 {
  {"Bob", "Butcher"},
  {"Anne", "Baker"},
  {"George", "Candlestick maker"}
};

* std::map - common methods

std::map<std::string, std::string> m {
  {"Bob", "Butcher"},
  {"Anne", "Baker"},
  {"George", "Candlestick maker"}
};

std::cout << m.size(); // 3
std::cout << m.max_size(); // a very large number
* No concept of front and back

std::map<std::string, std::string> m {
  {"Bob", "Butcher"},
  {"Anne", "Baker"},
  {"George", "Candlestick maker"}
};

std::pair<std::string, std::string> p1 {"James", "Mechanic"};
m.insert(p1);
m.insert(std::make_pair("Roger", "Ranger"));

std::map<std::string, std::string> m {
  {"Bob", "Butcher"},
  {"Anne", "Baker"},
  {"George", "Candlestick maker"}
};

! Frank is the key and the rhs is the value
m["Frank"] = "Teacher" // insert
m["Frank"] = "Instructor" // update value
m.at("Frank") = "Professor" // update value

std::map<std::string, std::string> m {
  {"Bob", "Butcher"},
  {"Anne", "Baker"},
  {"George", "Candlestick maker"}
};

m.erase("Anne"); // erase Anne

if(m.find("Bob") != m.end()) // find Bob
  std::cout << "Found Bob!";

auto it = m.find("George");
if(it != m.end())
  m.erase(it); // erase George

std::map<std::string, std::string> m {
  {"Bob", "Butcher"},
  {"Anne", "Baker"},
  {"George", "Candlestick maker"}
};

int num = m.count("Bob"); // returns 0 or 1 but 0 and 1 can be treated as a bool so we dont write the == operator

m.clear(); // remove all elements

m.empty(); // true or false

* std::multimap
#include <map>
* Ordered by key
* Allows duplicate elements
* All iterators are available

* std::unordered_map
#include <unordered_map>
* Elements are unordered
* No duplicate elements allowed
* No reverse iterators are allowed

* std::unordered_multimap
#include <unordered_map>
* Elements are unordered
* Allows duplicate elements
* No reverse iterators are allowed
*/

void display(const std::map<std::string, std::set<int>> &m) {
  if(m.empty()) {
    std::cout << "No emements to dispmay!" << std::endl;
    return;
  }
  std::cout << "[ ";
  for(const auto &elem : m) {
    std::cout << elem.first << ":[ ";
    for(const auto &set_elem : elem.second)
      std::cout << set_elem << " ";
    std::cout << "]";
  }
  std::cout << " ]" << std::endl;
}

template<typename T1, typename T2>
void display(const std::map<T1, T2> &m) {
  std::cout << "[ ";
  for(const auto &elem : m)
    std::cout << elem.first << ":" << elem.second << " ";
    std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "\nTest 1 ==============================\n" << std::endl;
  std::map<std::string, int> m {
    {"Larry", 3},
    {"Moe", 1},
    {"Curly", 2},
  };
  display(m);

  m.insert(std::pair<std::string, int>("Anna", 10));
  display(m);

  m.insert(std::make_pair("Joe", 5));
  display(m);

  m["Frank"] = 18;
  display(m);

  m["Frank"] += 10;
  display(m);

  m.erase("Frank");
  display(m);
  
  std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
  std::cout << "Count for Frank: " << m.count("Frank") << std::endl;
  
  auto it = m.find("Larry");
  if(it != m.end())
    std::cout << "Found: " << it->first << ":" << it->second << std::endl;

  m.clear();

  display(m);
}

void test2() {
  std::cout << "\nTest 2 ==============================\n" << std::endl;

  std::map<std::string, std::set<int>> grades {
    {"Larry", {100, 90}},
    {"Moe", {94}},
    {"Curly", {800, 90, 100}}
  };

  display(grades);

  grades["Larry"].insert(95); // insert 95 into the set

  display(grades);

  auto it = grades.find("Moe");
  if(it != grades.end())
    it->second.insert(1000); // insert 1000 into Moe's set
                             // it->first is the key, it->second is the value
  display(grades);
}

int main() {
  test1();
  test2();

  return 0;
}