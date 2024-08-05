#include <iostream>
#include <vector>

using namespace std;

void double_data(int *int_ptr) {
  *int_ptr *= 2;
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//int *dont_do_this();
//int *or_this();

//TODO TEST I WILL DELETE
int *larg_int(int* num1, int* num2);

int *largest_int(int *int_ptr1, int *int_ptr2);

int *create_array(size_t size, int init_value = 0);

void display(const vector<string> *const v) {
  //(*v).at(0) = "Alex"; //! ERROR it is a const
  for (auto str: *v)
    cout << str << " ";
  cout << endl;
  //v = nullptr; //! ERROR it is a const
}

void display_ar(int *array, int sentinel) {
  while (*array != sentinel)
    cout << *array++ << " ";
  cout << endl;
}

int main() {
  /*
  ? Passing pointers to a function
  * Pass-by-reference with pointer parameters
  * We can use pointers and the dereference operator to achieve pass-by-reference
  * The function parameter is a pointer
  * The actual parameter can be a pointer or address of a variable
 
  void double_data(int *int_ptr) {
    / *int_ptr *= 2;
  }

  * Calling this function:
  int value = 10;
  double_data(&value);
  cout << value << endl; // 20
  */

  //* Examples:

  int value = 10;
  int *val_ptr {nullptr};
  double_data(&value);
  cout << "Value: " << value << endl;
  
  cout << "-----------------------------------" << endl;
  val_ptr = &value;
  double_data(val_ptr);
  cout << "Value using pointer: " << *val_ptr << endl;

  int x = 100, y = 200;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  swap(&x, &y);
  cout << "After swapping:" << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  cout << "-----------------------------------" << endl;
  vector<string> names {"Alex", "Rita", "John"};
  display(&names);

  int scores[] {100, 98, 97, 79, 85, -1};
  display_ar(scores, -1);

  /*
  ? Returning a pointer from a function
  * Functions can also return pointers
  type *function();
  ? Should return pointers to:
    * Memory dynamically allocated in the function
    * To data that was passed in
  ! Never return a pointer to a local function variable!
  */
  int num1 = 15;
  int num2 = 20;
  int *num1_ptr = &num1;
  int *num2_ptr = &num2;

  cout << *largest_int(num1_ptr, num2_ptr) << endl;
  //or
  cout << *largest_int(&num1, &num2) << endl;

  int *my_array;
  my_array = create_array(100, 20);
  for (int i = 0; i < 100; i++)
    cout << my_array[i] << endl;
  delete[] my_array;

  //TODO TEST I WILL DELETE
  cout << *larg_int(&num1, &num2) << endl;
  
  return 0;
}

//* Example of returning a pointer from a function

int *largest_int(int *int_ptr1, int *int_ptr2) {
  if (*int_ptr1 > *int_ptr2)
    return int_ptr1;
  else
    return int_ptr2;
}

//* Example of returning dynamically allocated memory

int *create_array(size_t size, int init_value) {
  int *new_storage {nullptr};
  new_storage = new int[size];
  for (size_t i = 0; i < size; i++)
    *(new_storage + i) = init_value; // initializes all array elements to init_value
  return new_storage;
}

//! NEVER RETURN A POINTER TO A LOCAL VARIABLE
/*
int *dont_do_this() {
  int size{};
  return &size;
}

int *or_this() {
  int size{};
  int *int_ptr = &size;
  return int_ptr;
}
*/


//TODO TEST I WILL DELETE
int *larg_int(int* num1, int* num2) {
  if (*num1 > *num2)
    return num1;
  else 
    return num2;
}