#include <iostream>
#include <vector>

using namespace std;

int main() {
  /*
  
  ! Pointers
  ? A pointer is a variable whose value is an address.
  * An address can be another variable or a function.
  ? Let's say we make an int x = 10. This is stored in some address.
  ? We can declare a pointer variable that stores the address of x.
  ! To use the data that the pointer is pointing to you must know its type.

  * Why do we use pointers?
  ? Can’t I just use the variable or function itself?
  ! Yes, but not always
  * Inside functions, pointers can be used to access data that are defined outside the function. 
  * Those variables may not be in scope so you can’t access them by their name
  ? Pointers can be used to operate on arrays very efficiently
  ? We can allocate memory dynamically on the heap or free store.
    * This memory doesn’t even have a variable name. 
    * The only way to get to it is via a pointer
  ? With OO. pointers are how polymorphism works!
  ? Can access specific addresses in memory
    * useful in embedded and systems applications
  

  * Declaring pointers:
  variable_type *pointer_name;

  int *int_ptr;
  double* double_ptr; //! It doesn't matter where we put the asterisk
  char *char_ptr;
  string *string_ptr;
  
  ! We need to initialize pointers before we use them, if we don't, we will have garbage data:

  variable_type *pointer_name = nullptr; //? It means that it doesn't point anywhere

  int *int_ptr {};
  double* double_ptr = nullptr;
  char *char_ptr {nullptr};
  string *string_ptr {nullptr};

  * Accessing Pointer Address
  ? & is the address operator
  * Variables are stored in unique adresses
  * Unary operator
  * Evaluates to the address of its operand
    * Operand cannot be a constant or expression that evaluates to temp values
  */

  int num = 10;
  cout << "Value of num is: " << num << endl; // 10
  cout << "sizeof num is: " << sizeof(num) << endl; // 4 (bytes)
  cout << "Address of num is: " << &num << endl; // 0x245d9ff73c it's different each time

  //* Example

  int *p;
  cout << "Value of p is: " << p << endl; // 0xfbd71a97aa5e5928 - garbage
  cout << "Address of p is: " << &p << endl; // 0x1f165ffcb0
  cout << "sizeof p is: " << sizeof(p) << endl; // 8 (bytes)
  p = nullptr; // Sets p to point nowhere
  cout << "Value of p is: " << p << endl; // 0

  //! Don't confuse the size of a pointer and the size of what it points to
  //? All pointers in the program have the same size
  //* They may be pointing to very large or very small types

  int *p1 = nullptr;
  double *p2 = nullptr;
  unsigned long long *p3 = nullptr;
  vector<string> *p4 = nullptr;
  string *p5 = nullptr;

  //? The compiler will make sure that the address stored in a pointer variable is of correct type

  int score {10};
  double highTemp {100.7};
  double lowTemp {37.2};

  int *score_ptr = nullptr;

  score_ptr = &score; // OK
  //score_ptr = &highTemp; //! Compiler Error

  double *temp_ptr;

  temp_ptr = &highTemp; // points to highTemp
  temp_ptr = &lowTemp; // points to lowTemp
  temp_ptr = nullptr; // points to nothing

  //* Example:

  int numb = 10;
  int *numb_ptr = nullptr;

  numb_ptr = &numb;

  cout << "Value of numb: " << numb << endl;
  cout << "Address of numb: " << &numb << endl; // This and the below are the same because they both point to the address of numb
  cout << "Value of numb_ptr: " << numb_ptr << endl;

  //! Dereferencing a pointer:
  //? Access the data we are pointing to - dereferencing a pointer
  //* If score_ptr is a pointer and has a valid address,
  //* then, you can access the data at the address contained in the score_ptr using the dereferencing operator *.

  int hunnid = 100;
  int *hunnid_ptr = &hunnid;

  cout << *hunnid_ptr << endl; // 100 (displays the value inside the data that the pointer is pointing to)
  *hunnid_ptr = 200;
  cout << *hunnid_ptr << endl; // 200 (we can also change the value by using the dereferencing operator)
  cout << hunnid << endl; // 200

  double high_temp = 100.7;
  double low_temp = 37.4;
  double *temp = &high_temp;

  cout << *temp << endl; // 100.7
  temp = &low_temp;
  cout << *temp << endl; // 37.4

  string name = "Alex";
  string *name_ptr = &name;

  cout << *name_ptr << endl; // Alex
  *name_ptr = "Rita";
  cout << *name_ptr << endl; // Rita

  vector<string> people {"Kai", "Cole", "Jay"};
  vector<string> *people_ptr = nullptr;

  people_ptr = &people;

  cout << "First person: " << (*people_ptr).at(0) << endl; // Kai

  cout << "All together: ";
  for (auto person: *people_ptr) // Using a loop, it iterates in the vector, displaying each data using a pointer
    cout << person << ", ";
  cout << endl;

  //* Dynamic memory allocation
  //? Allocating storage from the heap at runtime
  //* We often don't know how much storage we need until we need it
  //* We can allocate storage for a variable at runtime
  //? Recall C++ arrays
    //* We had to explicitly provide the size and it was fixed
    //* But vectors grow and shrink dynamically
  //? We can use pointers to access newly allocated heap storage

  //* Using "new" to allocate storage
  int *int_ptr = nullptr;
  int_ptr = new int; // Creates an integer on the heap(memory that grows) and assigns the value 10 to it
  cout << int_ptr << endl; // 0x1ada9a7e860
  cout << *int_ptr << endl; // Garbage
  *int_ptr = 100;
  cout << *int_ptr << endl; // 100

  //* Using "delete" to deallocate (free) storage
  delete int_ptr;

  //* Using "new[]" to allocate storage for an array
  int *array_ptr = nullptr;
  int size {};
  cout << "How big do you want the array to be? ";
  cin >> size;
  array_ptr = new int[size]; // Size is the number of elements to allocate in the array

  for (int i = 1; i <= size; i++) { // Loops through the array and counts up to the size of the array
    array_ptr[i] = i;
    cout << array_ptr[i] << " ";
    cout << endl;
  }

  //* Using "delete[]" to deallocate storage for an array
  delete[] array_ptr;

  //* Examples

  size_t arSize {};
  cout << "How many temperatures? ";
  cin >> arSize;
  double *pTemp = nullptr;
  pTemp = new double[arSize];
  cout << pTemp << endl;
  delete[] pTemp;

  //? Relationship betwwen Arrays and Pointers
  //* The value of an array name is the address of the first element in the array
  //* The value of a pointer variable is an address
  //* If the pointer points to the same data type as the array element, then the pointer and array name can be used interchangeably(almost).

  int scores[] {100, 95, 89};
  
  cout << scores << endl; // 0xa4749ff524 address of the first element in the array
  cout << *scores << endl; // Always displays the first element in the array so 100

  int *scores_ptr = scores;

  cout << scores_ptr << endl; // 0xa4749ff524 address of the first element in the array
  cout << *scores_ptr << endl; // Always displays the first element in the array so 100

  cout << scores_ptr[0] << endl; // 100
  cout << scores_ptr[1] << endl; // 95
  cout << scores_ptr[2] << endl; // 89

  cout << scores_ptr << endl; // 0x61ff10
  //! Adds the address of the next integer which is 4 bytes away so it adds 4 to the hexadecimal address
  cout << (scores_ptr + 1) << endl; // 0x61ff14
  cout << (scores_ptr + 2) << endl; // 0x61ff18

  cout << *scores_ptr << endl; // 100
  //! Adds the address of the next integer which is 4 bytes away but we are dereferencing it so it displays the next element in the array
  cout << *(scores_ptr + 1) << endl; // 95
  cout << *(scores_ptr + 2) << endl; // 89

  /*
  ? Pointer Arithmetic
  ? Pointers can be used in
    * Assignment expressions
    * Arithmetic expressions
    * Comparison expressions
  ? C++ allows pointer arithmetic
  ? Pointer arithmetic only makes sense with raw arrays
  * (++) increments a pointer to point to the next array element
  int_ptr++;
  * (--) decrements a pointer to point to the previous array element
  int_ptr--;
  * (+) increments pointer by n * sizeof(type)
  int_ptr += n; or int_ptr = int_ptr + n;
  * (-) decrements pointer by n * sizeof(type)
  int_ptr -= n; or int_ptr = int_ptr - n;
  ? Subtracting two pointers
  * Determine the number of elements between the pointers
  * Both pointers must point to the same data type
  int n = int_ptr2 - int_ptr1;
  ? Comparing two pointers == and !=
  ? Determine if two pointers point to the same location
  ! does NOT compare the data where they point!
  string s1 = "Alex";
  string s2 = "Alex";

  string *p1 = &s1;
  string *p2 = &s2;
  string *p3 = &s1;

  p1 == p2; // false
  p1 == p3; // true
  p2 != p1; // true

  ? Comparing the data pointers point to
  ? Determine if two pointers point to the same data
  ! you must compare the referenced pointers
  string s1 = "Alex";
  string s2 = "Alex";

  string *p1 = &s1;
  string *p2 = &s2;
  string *p3 = &s1;

  / *p1 == *p2; // true
  / *p1 == *p3; // true
  / *p2 != *p1; // false
  */

  //* Examples

  int randNums[] {10, 70, 32, 69, 4, -1};
  int *rand_nums = randNums;
  /*
  while (*rand_nums != -1) {  Loops between the array and stops when it reaches -1
    cout << *rand_nums << " ";
    rand_nums++;
  }

  or
  */
  while(*rand_nums != -1)
    cout << *rand_nums++ << endl;

  char jusName[] {"Alex"};
  char *char_ptr1 = nullptr;
  char *char_ptr2 = nullptr;

  char_ptr1 = &jusName[0];
  char_ptr2 = &jusName[3];

  cout << "In the string " << jusName << ", " << *char_ptr1 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr2 << endl;

  /*
  ? Passing pointers to a function
  ? Const and Pointers
  * There are several ways to qualify pointers using const
    * Pointers to constants
    * Constant pointers
    * Constant pointers to constants
  ? Pointers to constants
  ! The data pointed to by the pointers is constant and CANNOT be changed
  ? The pointer itself can change and point somewhere else
  int high_score {100};
  int low_score {65};
  const int *score_ptr = &high_score;

  / *score_ptr = 86; //! ERROR
  score_ptr = &low_score; // OK

  ? Constant pointers
  ? The data pointed to by the pointers can be changed
  ! The pointer itself CANNOT change and point somewhere else
  int high_score {100};
  int low_score {65};
  int *const score_ptr = &high_score;

  / *score_ptr = 86; // OK
  score_ptr = &low_score; //! ERROR

  ? Constant pointers to constants
  ! The data pointed to by the pointers is constant and CANNOT be changed
  ! The pointer itself CANNOT change and point somewhere else
  int high_score {100};
  int low_score {65};
  const int *const score_ptr = &high_score;

  / *score_ptr = 86; //! ERROR
  score_ptr = &low_score; //! ERROR

  ! Potential Pointer Pitfalls

  * Uninitialized pointers:
  int *int_ptr; // pointing anywhere
  / *int_ptr = 100; // potential crash

  * Dangling pointers:
  ? Pointer that is pointing to released memory
  * For example, 2 pointers point to the same data
  * 1 pointer releases the data with delete
  * The other pointer accesses the release data
  ? Pointer that points to memory that is invalid
  * We saw this when we returned a pointer to a function local variable

  * Not checking if new failed to allocate memory:
  * If new fails an exception is thrown
  * We can use exception handling to catch exceptions
  * Dereferencing a null pointer will cause your program to crash

  * Leaking memory:
  * Forgetting to release allocated memory with delete
  ! If you lose your pointer to the storage allocated on the heap, you have no way to get to that storage again
  * The memory is orphaned or leaked
  * One of the most common pointer problems
  */

  return 0;
}