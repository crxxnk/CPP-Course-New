#include <iostream>
#include <stack>
#include <vector>
#include <list>

/*
CA = Container Adaptors
! std::stack
? Last-in First-out(LIFO) data structure
? Implemented as an adapter over other STL container, can be implemented as a vector, list, or deque
? All operations occur on one end of the stack(top)
* No iterators supported

#include <stack>
* push - insert an element at the top of the stack
* pop - remove an element from the top of the stack
* top - access the top element of the stack
* empty - is the stack empty?
* size - number of elements in the stack

* std::stack - initialization
std::stack<int> s; // deque
std::stack<int, std::vector<int>> s1 // vector
std::stack<int, std::list<int>> s2; // list
std::stack<int, std::deque<int>> s3; // deque

* std::stack - common methods
std::stack<int> s;
s.push(10); // 10

s.push(20); // 20
               10

s.push(30); // 30
               20
               10

s.top(); // 30
s.pop(); // 30 is removed
s.pop(); // 20 is removed
s.size(); // 1
*/

template<typename T>
void display(std::stack<T> s) {
  std::cout << "[ ";
  while(!s.empty()) {
    T elem = s.top();
    s.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  std::stack<int> s;
  std::stack<int, std::vector<int>> s1;
  std::stack<int, std::list<int>> s2;
  std::stack<int, std::deque<int>> s3;

  for(int i: {1,2,3,4,5})
    s.push(i);
  display(s);

  s.push(100);
  display(s);

  s.pop();
  s.pop();
  display(s);

  while(!s.empty())
    s.pop();
  display(s);

  std::cout << "Size: " << s.size() << std::endl;

  s.push(10);
  display(s);

  s.top() = 100;
  display(s);

  return 0;
}