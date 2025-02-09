#include <iostream>
#include <vector>
#include <algorithm>
/*
! std::vector

#include <vector>
? Dynamic size
  * Handled automatically
  * Can expand and contract as needed
  * Elements are stored in contiguous memory as an array
? Direct element access(constant time)
? Rapid insertion and deletion at the back(constant time)
? Insertion or removal of elements(linear time)
? All iterators available and may invalidate

std::vector<int> vec {1,2,3};
* first element     last element
  front() // 1      back() // 3

vec.push_back(4)
* first element     last element
  front() // 1      back() // 4

* std::vector - initialization and assignment
std::vector<int> vec {1,2,3,4,5};
std::vector<int> vec1(10,100); // ten 100s
std::vector<std::string> stooges {
  "Larry",
  "Moe",
  "Curly"
};
vec1 = {2,4,6,8,10};

* std::vector - common methods
std::vector<int> vec {1,2,3,4,5};
vec.size(); // 5 (number of elements in the vector)
vec.capacity(); // 5
vec.max_size; // a very large number

vec.at(0); // 1
vec[1]; // 2

vec.front(); // 1
vec.back(); //5

Person p1{"Larry", 18};
std::vector<Person> vec;
vec.push_back(p1); // add p1 to the back
vec.pop_back(p1); // remove p1 from the back
vec.push_back(Person{"Larry", 18}); // temporary person object is created
vec.emplace_back("Larry", 18); // directly constructs the person object in place *efficient*

std::vector<int> vec1 {1,2,3,4,5};
std::vector<int> vec2 {10,20,30,40,50};
vec1.empty(); // 0 (false)
vec1.swap(vec2) // swaps the 2 vectors
std::sort(vec1.begin(), vec1.end());

std::vector<int> vec1 {1,2,3,4,5};
std::vector<int> vec2 {10,20,30,40,50};

auto it = std::find(vec1.begin(), vec1.end(), 3); // iterator points at 3
vec1.insert(it, 10); // inserts the number 10 before the iterator element *1,2,10,3,4,5*

it = std::find(vec1.begin(), vec1.end(), 4);
vec1.insert(it, vec2.begin(), vec2.end()); // inserts the whole vec2 before the iterator element *1,2,10,3,10,20,30,40,50,4,5*
*/

class Person {
  friend std::ostream &operator<<(std::ostream &os, const Person &obj);
  std::string name;
  int age;
public:
  Person() = default;
  Person(std::string name, int age): name(name), age(age) {}
  bool operator<(const Person &rhs) const {
    return this->age < rhs.age;
  }
  bool operator==(const Person &rhs) const {
    return (this->name == rhs.name && this->age == rhs.age);
  }
  bool operator>(const Person &rhs) const {
    return this->age > rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &obj) {
  os << obj.name << ": " << obj.age;
  return os;
}

void display2(const std::vector<int> &vec){
  std::cout << "[";
  std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " ";});
  std::cout << "]" << std::endl;
}

template<typename T>
void display(const std::vector<T> &vec) {
  if(vec.empty()) {
    std::cout << "No elements to display!" << std::endl;
    return;
  }
  std::cout << "[";
  auto it = vec.begin();
  while(it != vec.end()) {
    if(it == (vec.end() - 1))
      std::cout << *it;
    else
      std::cout << *it << " ";
    it++;
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "Test 1 ==============================\n" << std::endl;
  std::vector<int> vec {1,2,3,4,5};
  display(vec);
  std::vector<int> vec1 (10, 100);
  display(vec1);
}

void test2() {
  //! Whenever we exceed the capacity, it will double
  std::cout << "\nTest 2 ==============================\n" << std::endl;
  std::vector<int> vec {1,2,3,4,5};
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  vec.push_back(6);
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  vec.shrink_to_fit(); // shrinks the amount of storage allocated to exactly the vector size
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  vec.reserve(100); // sets the capacity to 100
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;
}

void test3() {
  std::cout << "\nTest 3 ==============================\n" << std::endl;
  std::vector<int> vec {1,2,3,4,5};
  display(vec);
  vec[0] = 100;
  vec.at(1) = 200;
  display(vec);
}

void test4() {
  std::cout << "\nTest 4 ==============================\n" << std::endl;
  std::vector<Person> people;
  Person p1 {"Alex", 15};
  display(people);
  people.push_back(p1);
  display(people);
  people.push_back(Person{"Rita", 14});
  display(people);
  people.emplace_back("Maria", 17); //! Use emplace_back!!!
  display(people);
}

void test5() {
  std::cout << "\nTest 5 ==============================\n" << std::endl;
  std::vector<Person> people {
    {"Larry", 18},
    {"Moe", 25},
    {"Curly", 30}
  };
  display(people);
  std::cout << "Front: " << people.front() << std::endl;
  std::cout << "Back: " << people.back() << std::endl;
  people.pop_back();
  display(people);
}

void test6() {
  std::cout << "\nTest 6 ==============================\n" << std::endl;
  std::vector<int> vec{1,2,3,4,5};
  display(vec);

  vec.clear();
  display(vec);

  vec = {1,2,3,4,5,6,7,8,9,10};
  display(vec);
  vec.erase(vec.begin(), vec.begin() + 2);
  display(vec);

  vec = {1,2,3,4,5,6,7,8,9,10};
  auto it = vec.begin();
  while(it != vec.end()) {
    if(*it % 2 == 0)
      vec.erase(it);
    else
      it++;
  }
  display(vec);
}

void test7() {
  std::cout << "\nTest 7 ==============================\n" << std::endl;
  std::vector<int> vec1{1,2,3,4,5};
  std::vector<int> vec2{10,20,30,40,50};

  display(vec1);
  display(vec2);
  std::cout << std::endl;

  vec2.swap(vec1);
  display(vec1);
  display(vec2);
}

void test8() {
  std::cout << "\nTest 8 ==============================\n" << std::endl;

  std::vector<int> vec1 {1,21,3,40,12};

  display(vec1);
  std::sort(vec1.begin(), vec1.end());
  display(vec1);
}

void test9() {
  // std::back_inserter constructs a back-insert iterator that inserts new elements
  // at the end of the container it applied to. It's a special ouput iterator
  // It's awesome!!! and very efficient
  // There is also a front_inserter we can use with deques and lists
  // Copy one list to another using an iterator and back_inserter

  std::cout << "\nTest 9 ==============================\n" << std::endl;

  std::vector<int> vec1 {1,2,3,4,5};
  std::vector<int> vec2 {10,20};

  display(vec1);
  display(vec2);
  std::cout << std::endl;

  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2)); // Copies the entire vec1 to vec2
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  // Copy_if the element is even
  vec1 = {1,2,3,4,5};
  vec2 = {10,20};

  display(vec1);
  display(vec2);
  std::cout << std::endl;

  std::copy_if(
    vec1.begin(),
    vec1.end(),
    std::back_inserter(vec2),
    [](int x) { return x % 2 == 0; }
  ); // Vertical for fun
  display(vec1);
  display(vec2);
}

void test10() {
  std::cout << "\nTest 10 ==============================\n" << std::endl;

  std::vector<int> vec1 {1,2,3,4,5}; //! Throws garbage numbers if this vector is bigger than the other
  std::vector<int> vec2 {10,20,30,40,50}; //! And doesn't do anything if this vector is bigger
  std::vector<int> vec3;

  // 1 * 10, 2 * 20, 3 * 30, 4 * 40, 5 * 50 and store the results in vec3
  std::transform(
    vec1.begin(),
    vec1.end(),
    vec2.begin(),
    std::back_inserter(vec3),
    [](int x, int y) { return x * y; }
  );
  display(vec3);
}

void test11() {
  std::cout << "\nTest 11 ==============================\n" << std::endl;

  std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
  std::vector<int> vec2 {100,200,300,400};

  display(vec1);
  display(vec2);
  std::cout << std::endl;

  auto it = std::find(vec1.begin(), vec1.end(), 5);
  if(it != vec1.end()) {
    std::cout << "Inserting..." << std::endl;
    vec1.insert(it, vec2.begin(), vec2.end());
  }
  else
    std::cout << "Sorry, 5 not found" << std::endl;
  display(vec1);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();

  return 0;
}