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
  
  return 0;
}