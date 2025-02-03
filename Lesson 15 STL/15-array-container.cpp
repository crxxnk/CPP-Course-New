#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

/*
! std::array
#include <array>
? Fixed size
  * Size must be known at compile time
? Direct element access
? Provides access to the underlying raw array
* Use instead of raw arrays when possible
? All iterators available and do not invalidate

* Initialization and assignment
std::array<int, 5> arr1 {1,2,3,4,5};

std::array<std::string, 3> stooges {
  std::string("Larry"),
  "Moe",
  std::string("Curly")
};

* Common methods
std::array<int, 5> arr {1,2,3,4,5};
std::cout << arr.size(); // 5

std::cout << arr.at(0); // 1
std::cout << arr[1]; // 2

std::cout << arr.front(); // 1
std::cout << arr.back(); // 5

std::array<int, 5> arr1 {10,20,30,40,50};
std::cout << arr.empty(); // 0 (false)
std::cout << arr.max_size(); // 5

arr.swap(arr1);
int *data = arr.data();
*/

void display(const std::array<int, 5> &arr) {
  auto it = arr.begin();
  std::cout << "[ ";
  while(it != arr.end()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void test1() {
  std::cout << "============= Test 1 =============" << std::endl;

  std::array<int, 5> arr1 {1,2,3,4,5};
  std::array<int, 5> arr2;

  display(arr1);
  display(arr2); // Elements are not initialized and the array contains garbage

  arr2 = {10,20,30,40,50};

  display(arr1);
  display(arr2);

  std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
  std::cout << "Size of arr2 is: " << arr2.size() << std::endl;

  arr1[0] = 1000;
  arr1.at(1) = 2000;
  display(arr1);

  std::cout << "Front of arr2: " << arr2.front() << std::endl;
  std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

void test2() {
  std::cout << "============= Test 2 =============" << std::endl;

  std::array<int, 5> arr1 {1,2,3,4,5};
  std::array<int, 5> arr2 {10,20,30,40,50};

  arr1.fill(0);

  display(arr1);
  display(arr2);

  arr1.swap(arr2);

  display(arr1);
  display(arr2);
}

void test3() {
  std::cout << "============= Test 3 =============" << std::endl;

  std::array<int, 5> arr1 {1,2,3,4,5};
  int* ptr = arr1.data(); // points to the first element
  std::cout << ptr << std::endl;
  *ptr = 1000; // changes the first element

  display(arr1);
}

void test4() {
  std::cout << "============= Test 4 =============" << std::endl;

  std::array<int, 5> arr1 {2,1,4,5,3};
  display(arr1);

  std::sort(arr1.begin(), arr1.end());
  display(arr1);
}

void test5() {
  std::cout << "============= Test 5 =============" << std::endl;

  std::array<int, 5> arr1 {2,1,4,5,3};

  std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
  auto max_num = std::max_element(arr1.begin(), arr1.end());
  std::cout << "Min: " << *min_num << std::endl << "Max: " << *max_num << std::endl;
}

void test6() {
  std::cout << "============= Test 6 =============" << std::endl;

  std::array<int, 5> arr1 {2,1,3,3,5};
  auto adjacent = std::adjacent_find(arr1.begin(), arr1.end()); // Returns the first occurence two elements that are next to each other
  if(adjacent != arr1.end())
    std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
  else
    std::cout << "No adjacent elements found" << std::endl;
}

void test7() {
  std::cout << "============= Test 7 =============" << std::endl;

  std::array<int, 5> arr1 {1,2,3,4,5};

  int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
  std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

void test8() {
  std::cout << "============= Test 8 =============" << std::endl;

  std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};

  int count = std::count(arr1.begin(), arr1.end(), 3);
  std::cout << "Found 3 " << count << " times" << std::endl;
}

void test9() {
  std::cout << "============= Test 9 =============" << std::endl;

  std::array<int, 10> arr1 {1,2,3,50,60,70,80,200,300,400};
  // find how many numbers are between 10 and 200 -> 50,60,70,80
  int count = std::count_if(arr1.begin(), arr1.end(), [](int x){ return x > 10 && x < 200; });
  std::cout << "Found " << count << " matches" << std::endl;
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();

  return 0;
}