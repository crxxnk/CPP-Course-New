#include <iostream>
#include <queue>

/*
! std::queue
? First-in First-out(FIFO) data structure
? Implemented as an adapter over other STL container, can be implemented as a list or deque
? Elements are pushed at the back and popped from the front
* No iterators supported

#include <queue>
* push - insert an element at the back of the queue
* pop - remove an element from the front of the queue

* front - access the element at the front
* back - access the element at the back

* empty - is the queue empty?
* size - number of elements in the queue

* std::queue - initialization
std::queue<int> q;
std::queue<int, std::list<int>> q2; // list
std::queue<int, std::deque<int>> q2; // deque

* std::queue - common methods
std::queue<int> q;

q.push(10); // 10

q.push(20); // 20 10

q.push(30); // 30 20 10

q.front(); // 10
q.back(); // 30

q.pop(); // remove 10 [30 20]
q.pop(); // remove 20 [30]
q.size(); // 1
*/

template<typename T>
void display(std::queue<T> q) {
  std::cout << "[ ";
  while(!q.empty()) {
    T elem = q.front();
    q.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  std::queue<int> q;
  
  for(int i: {1,2,3,4,5})
    q.push(i);
  display(q);
  std::cout << "Front: " << q.front() << std::endl;
  std::cout << "Back: " << q.back() << std::endl;

  q.push(100);
  display(q);

  q.pop();
  q.pop();
  display(q);

  while(!q.empty())
    q.pop();
  display(q);

  std::cout << "Size: " << q.size() << std::endl;

  q.push(10);
  q.push(100);
  q.push(1000);
  display(q);

  std::cout << "Front: " << q.front() << std::endl;
  std::cout << "Back: " << q.back() << std::endl;

  q.front() = 5;
  q.back() = 5000;

  display(q);
  std::cout << "Front: " << q.front() << std::endl;
  std::cout << "Back: " << q.back() << std::endl;

  return 0;
}