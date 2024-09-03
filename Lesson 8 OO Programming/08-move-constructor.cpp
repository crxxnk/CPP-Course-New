#include <iostream>
#include <vector>

using namespace std;

/*
! Move Constructor
? Sometimes when we execute code, the compiler creates unnamed temporary values
int total = 0;
total = 100 + 200;
* 100 + 200 is evaluated and 300 is stored in an unnamed temp value
* the 300 is then stored in the variable total
* then the temp value is discarded
? The same happens with objects as well

! When is it useful?
* Sometimes, copy constructors are called many times automatically due to the copy semantics of C++
* Copy constructors doing deep copying can have a significant performance bottleneck
* C++11 introduced move semantics and the move constructor
* Move constructor moves an object rather than copy it
* Optional but recommended when you have a raw pointer
* Copy elision - C++ may optimize copying away completely (RVO-Return Value Optimization)

! r-value references
? Used in moving semantics and perfect forwarding
? Move semantics is all about r-value references
? Used by move constructor and move assignment operator to efficiently move an object rather than copy it
? R-value reference operator(&&)
* Examples:

int x = 100;
int &l_ref = x; // l-value reference
l_ref = 10; // change x to 10

int &&r_ref = 200; // r-value ref
r_ref = 300; // change r-ref to 300

int &&x_ref = x; //! Compiler error

* l-value reference parameters
int x = 100;

void func(int &num);

func(x); // Call with l-value reference
func(200) //! Error - 200 is an r-value

* r-value reference parameters
int x = 100;

void func(int &&num);

func(200); // Call with r-value reference
func(x); //! Error - x is an l-value
*/

//* Move constructor example:


class Move
{
private:
  int *data;
public:
  void setDataValue(int d) { *data = d; }
  int getDataValue() { return *data; }
  Move(int d);
  Move(const Move &source);
  Move(Move &&source); // Move constructor
  ~Move();
};

Move::Move(int d) {
  data = new int;
  *data = d;
  std::cout << "Constructor for: " << d << std::endl;
}

Move::Move(const Move &source): Move(*source.data) {
  std::cout << "Copy constructor for: " << *data << std::endl;
}

Move::Move(Move &&source): data(source.data) {
  source.data = nullptr; // Steal the data and null out the source pointer
  std::cout << "Move constructor for: " << *data << std::endl;
}

Move::~Move() {
  if(data != nullptr)
    std::cout << "Destructor freeing data for: " << *data << std::endl;
  else
    std::cout << "Destructor freeing data for nullptr" << std::endl;
  delete data;
}

int main()
{
  std::vector<Move> vec;
  vec.push_back(Move(10)); // Move constructor called here
  // vec.push_back(Move(20)); // Move constructor called here

  return 0;
}