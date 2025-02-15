#include <iostream>
#include <queue>

/*
! std::priority_queue
? Allows insertions and removal of elements in order from the front of the container
? Elements are stored internally as a vector by default
? Elements are inserted in priority order (largest value will always be at the front)
* No iterators are supported

#include <queue>
* push - insert an element into sorted order
* pop - removes the top element (greatest)

* top - access the top element (greatest)

* empty - is the queue empty?
* size - number of elements in the queue

* std::priority_queue - initialization
std::priority_queue<int> pq;

pq.push(10);
pq.push(20);
pq.push(3);
pq.push(4);

std::cout << pq.top(); // 20 (largest)
pq.pop(); // remove 20
pq.top(); // 10 (largest)
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
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
  os << rhs.name << ":" << rhs.age;
  return os;
}

template<typename T>
void display(std::priority_queue<T> pq) {
  std::cout << "[ ";
  while(!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "\nTest 1 ==============================\n" << std::endl;

  std::priority_queue<int> pq;
  for(int i : {3,5,7,12,23,12,4,100,0,3,5,7})
    pq.push(i);
  
  std::cout << "Size: " << pq.size() << std::endl;
  std::cout << "Top: " << pq.top() << std::endl;

  display(pq);

  pq.pop();

  display(pq);
}

void test2() {
  std::cout << "\nTest 2 ==============================\n" << std::endl;

  std::priority_queue<Person> pq;
  pq.push(Person{"A", 10});
  pq.push(Person{"B", 1});
  pq.push(Person{"C", 14});
  pq.push(Person{"D", 18});
  pq.push(Person{"E", 7});
  pq.push(Person{"F", 27});

  display(pq);
}

int main() {
  test1();
  test2();

  return 0;
}