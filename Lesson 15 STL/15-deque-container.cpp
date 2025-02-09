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
  std::cout << "\nTest 1 ==============================\n" << std::endl;
}

int main()
{
  test1();

  return 0;
}