/*
! The Standard Template Library
? A library of powerful, reusable, adaptable, generic classes and functions
* Implemented using C++ templates
* Implements common data structures and algorithms
* Huge class library!!

? Why use STL?
* Assortment of commonly used containers
* Known time and size complexity
* Tried and tested - Reusability
* Consistent, fast and type-safe
* Extensible

? Elements of the STL
* Containers
  * Collections of objects or primitive types(array, vector, deque, stack, set, map, etc.)
* Algorithms
  * Functions for processing sequences of elements from containers(find, max, count, accumulate, sort, etc.)
* Iterators
  * Generate sequences of element from containers(forward, reverse, by value, by reference, constant, etc.)

* Simple examples
#include <vector>
#include <algorithm>

std::vector<int> v {1,5,3};
std::sort(v.begin(), v.end()); // sorts the vector
for(auto elem : v)
  std::cout << elem << std::endl;
* Output:
1
3
5

std::vector<int> v {1,5,3};
std::sort(v.begin(), v.end()); // sorts the vector
std::reverse(v.begin(), v.end()); // reverses the vector
for(auto elem : v)
  std::cout << elem << std::endl;
* Output:
5
3
1

int sum;
sum = std::accumulate(v.begin(), v.end(), 0); // third parameter is the "plus", if its 1 for example the result will be 10
std::cout << sum << std::endl;
* Output:
9 // 1+3+5

? Types of Containers
* Sequence containers
  * array, vector, list, forward_list, deque
* Associative containers
  * set, multi set, map, multi map
* Container adapters
  * stack, queue, priority queue

? Types of Iterators
* Input iterators - from the container to the program
* Output iterators - from the program to the container
* Forward iterators - navigate one item at a time in one direction
* Bi-directional iterators - navigate one item at a time both directions
* Random access iterators - directly access a container item

? Types of Algorithms
* About 60 algorithms in the STL
* Non-modifying
* Modifying
*/