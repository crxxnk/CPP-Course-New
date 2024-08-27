#include <iostream>

using namespace std;

/*
! Shallow vs. Deep Copying
? Consider a class that contains a pointer as a data member
? Constructor allocates storage dynamically and initializes the pointer
? Destructor releases the memory allocated by the constructor
? What happens in the default copy constructor?

! Default copy constructor
* memberwise copy
* Each data member is copied from the source object
* The pointer is copied, NOT what it points to (shallow copy)
! Problem: when we release the storage in the destructor,
! the other object still refers to the released storage

! User-provided copy constructor
? Create a copy of the pointed-to data
? Each copy will have a pointer to unique storage in the heap
? Deep copy when you have a raw pointer as a class data member
*/

//* Shallow Copy:

class Shallow
{
private:
  int *data;
public:
  void setDataValue(int d) { *data = d; }
  int getDataValue() { return *data; }
  Shallow(int d);
  Shallow(const Shallow &source);
  ~Shallow();
};

Shallow::Shallow(int d) {
  data = new int; // allocate storage
  *data = d;
}

Shallow::Shallow(const Shallow &source): data(source.data) {
  cout << "Copy constructor - shallow copy" << endl;
}

Shallow::~Shallow() {
  delete data; // free storage
  cout << "Destructor releasing memory..." << endl;
}

void displayShallow(Shallow s){
  cout << s.getDataValue() << endl;
}

//* Deep Copy:

class Deep
{
private:
  int *data;
public:
  void setDataValue(int d) { *data = d; }
  int getDataValue() { return *data; }
  Deep(int d);
  Deep(const Deep &source);
  ~Deep();
};

Deep::Deep(int d) {
  data = new int;
  *data = d;
}

/*
Deep::Deep(const Deep &source) {
  data = new int; //! allocate storage for the copy
' *data = *source.data;
  cout << "Copy constructor - deep copy" << endl;
}

!or
*/

Deep::Deep(const Deep &source): Deep{*source.data} {
  cout << "Copy constructor - deep copy" << endl;
}

Deep::~Deep() {
  delete data; // free storage
  cout << "Destructor releasing memory..." << endl;
}

void displayDeep(Deep s){
  cout << s.getDataValue() << endl;
}

int main()
{
  // Shallow obj1 {100};
  // displayShallow(obj1);

  // Shallow obj2 {obj1};
  // obj2.setDataValue(1000);

  Deep obj1 {100};
  displayDeep(obj1);

  Deep obj2 {obj1};
  obj2.setDataValue(1000);

  return 0;
} //! Problem right here using shallow copy, after the destructor is called from going out of scope