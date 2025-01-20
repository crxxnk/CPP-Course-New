#include <vector>
#include <iostream>
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