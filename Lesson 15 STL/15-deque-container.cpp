#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

/*
! std::deque (double ended queue)

#include <deque>

? Dynamic size
  * Handled automatically
  * Can expand and contract as needed
  * Elements are NOT stored in contiguous

? Direct element access(constant time)
? Rapid insertion and deletion at the front and back(constant time)
? Insertion or removal of elements(linear time)
? All iterators available and may invalidate

* std::deque - initialization and assignment
std::deque<int> d {1,2,3,4,5};
std::deque<int> d1(10, 100); // ten 100s

std::deque<std::string> stooges {
  std::string("Larry"),
  "Moe",
  std::string("Curly")
};

d = {2,4,6,8,10};

! In a deque there is also a push_front method (and pop_front and emplace_front also)
std::deque<int> d {1,2,3};
d.push_back(4); // 1,2,3,4
d.push_front(0); // 0,1,2,3,4
*/

template<typename T>
void display(const std::deque<T> &d) {
  std::cout << "[ ";
  for(const auto &elem : d)
    std::cout << elem << " ";
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "\nTest 1 ==============================\n" << std::endl;

  std::deque<int> d{1,2,3,4,5};
  display(d);

  d = {2,4,5,6};
  display(d);

  std::deque<int> d1 (10, 100); // 10 100s
  display(d1);

  d[0] = 100;
  d.at(1) = 200;
  display(d);
}

void test2() {
  std::cout << "\nTest 2 ==============================\n" << std::endl;
  std::deque<int> d {0,0,0};
  display(d);

  d.push_front(100);
  d.push_front(200);
  display(d);

  std::cout << "Front: " << d.front() << std::endl;
  std::cout << "Back: " << d.back() << std::endl;
  std::cout << "Size: " << d.size() << std::endl;

  d.pop_back();
  d.pop_front();
  display(d);
}

void test3() {
  std::cout << "\nTest 3 ==============================\n" << std::endl;

  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  std::deque<int> d;

  for(const auto &elem : vec) {
    if(elem % 2 == 0)
      d.push_back(elem);
    else
      d.push_front(elem);
  }
  display(d);
}

void test4() {
  std::cout << "\nTest 4 ==============================\n" << std::endl;
  
  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  std::deque<int> d;

  for(const auto &elem : vec)
    d.push_front(elem);
  display(d);

  d.clear();

  for(const auto &elem : vec)
    d.push_back(elem);
  display(d);
}

void test5() {
  std::cout << "\nTest 5 ==============================\n" << std::endl;
  
  std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
  std::deque<int> d;

  std::copy(vec.begin(), vec.end(), std::front_inserter(d));
  display(d);

  d.clear();

  std::copy(vec.begin(), vec.end(), std::back_inserter(d));
  display(d);
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  test5();

  return 0;
}