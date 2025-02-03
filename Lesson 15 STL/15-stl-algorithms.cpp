#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>
/*
! Algorithms
? STL algorithms work on sequences of container elements provided to them by an iterator
? STL has many common and useful algorithms
? Too many to describe in this section
  * http://en.cppreference.com/w/cpp/algorithm
? Many algorithms require extra information in order to do their work
  * Functors(function objects)
  * Function pointers
  * Lambda expressions(C++11)

#include <algorithm>
? Different containers support different types of iterators
  * Determines the types of algorithms supported

? All STL algorithms expect iterators as arguments
  * Determines the sequence obtained from the container

! Iterator invalidation
? Iterators point to container elements
? It's possible iterators become invalid during processing
* Suppose we are iterating over a vector of 10 elements
  ? And we clear() the vector while iterating? What happens?
  ! Undefined behavior - our iterators are pointing to invalid locations

* Example algorithm - find with primitive types
? The find algorithm tries to locate the first occurence of an element in a container
* Lots of variations
? Returns an iterator pointing to the located element or end()
std::vector<int> vec {1,2,3};
auto loc = std::find(vec.begin(), vec.end(), 3);
if(loc != vec.end())
  std::cout << *loc << std::endl; // 3

! Find needs to be able to compare an object
* operator== is used and must be provided by your class
* Example:
struct Player{
  std::string name;
  int health;
  int stamina;
  friend std::ostream &operator<<(std::ostream &os, const Player &player);
  bool operator==(const Player &player);
};

std::ostream &operator<<(std::ostream &os, const Player &player) {
  os << player.name << " " << player.health << " " << player.stamina;
  return os;
}

int main()
{
  Player p {"Hero", 100, 12};
  Player p1 {"Bals", 50, 1365};
  std::vector<Player> team{p, p1};
  auto loc = std::find(team.begin(), team.end(), p);
  if(loc != team.end())
    std::cout << *loc << std::endl;

  return 0;
}

bool Player::operator==(const Player &player)
{
  if(health == player.health && name == player.name && stamina == player.stamina)
    return true;
  return false;
}

* Example algorithm - for_each
? for_each algorithm applies a function to each element in the iterator sequence
? Function must be provided to the algorithm as:
  * Functor(function object)
  * Function pointer
  * Lambda expression(C++11)
* Let's square each element

! for_each - using a functor
struct Square_Functor {
  void operator() (int x) { // overload () operator
    std::cout << x * x << " ";
  }
};
Square_Functor square; // function object
std::vector<int> vec {1,2,3,4};
std::for_each(vec.begin(), vec.end(), square); // 1 4 9 16

! for_each - using a function pointer
void square(int x) {
  std::cout << x * x << " ";
}
std::vector<int> vec {1,2,3,4};
std::for_each(vec.begin(), vec.end(), square);

! for_each - using a lambda expression
std::vector<int> vec {1,2,3,4};
std::for_each(vec.begin(), vec.end(),[](int x) { std::cout << x * x << " "; })
*/

class Person {
  std::string name;
  int age;
public:
  Person() = default;
  Person(std::string name, int age): name(name), age(age) {}
  bool operator<(const Person &rhs) const { return this->age < rhs.age; }
  bool operator==(const Person &rhs) const {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

void find_test() {
  /*
  std::vector<int> vec {1,2,3,4,5};
  auto loc = std::find(std::begin(vec), std::end(vec), 1);
  if(loc != std::end(vec))
    std::cout << "Found the element: " << *loc << std::endl;
  else
    std::cout << "Couldn't find the element" << std::endl;
  */

  std::list <Person> players {
    {"Larry", 18},
    {"Moe", 20},
    {"Curly", 21}
  };
  auto loc1 = std::find(std::begin(players), std::end(players), Person("Moe", 20));
  if(loc1 != std::end(players))
    std::cout << "Found Moe" << std::endl;
  else
    std::cout << "Couldn't find Moe" << std::endl;
}

void count_test() {
  std::vector<int> vec {1,2,3,4,5,1,2,1};
  int num = std::count(vec.begin(), vec.end(), 1);
  std::cout << num << " occurences found" << std::endl;
}

void count_if_test() {
  std::vector<int> vec {1,2,3,4,5,1,2,1,100};
  int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
  std::cout << num << " even numbers found" << std::endl;

  num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
  std::cout << num << " odd numbers found" << std::endl;

  num = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5; });
  std::cout << num << " numbers are greater or equal to 5" << std::endl;
}

void replace_test() {
  std::vector<int> vec {1,2,3,4,5,1,2,1};
  for(auto i: vec)
    std::cout << i << " ";
  std::cout << std::endl;

  std::replace(vec.begin(), vec.end(), 1, 100);
    for(auto i: vec)
    std::cout << i << " ";
  std::cout << std::endl;
}

void all_of_test() {
  std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};
  if(std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 10; }))
    std::cout << "All the elements are > 10" << std::endl;
  else
    std::cout << "Not all the elements are > 10" << std::endl;
  
  if(std::all_of(vec1.begin(), vec1.end(), [](int x) { return x < 20; }))
    std::cout << "All the elements are < 20" << std::endl;
  else
    std::cout << "Not all the elements are < 20" << std::endl;
}

void string_transform_test() {
  std::string str1 = "This is a test";
  std::cout << "Before transform: " << str1 << std::endl;
  std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
  std::cout << "After transform: " << str1 << std::endl;
}

int main()
{
  string_transform_test();

  return 0;
}