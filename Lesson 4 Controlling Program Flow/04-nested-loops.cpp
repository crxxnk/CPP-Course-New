#include <iostream>
#include <vector>

using namespace std;

int main() {
  //! Nested loops
  //? Nested loops are loops inside other loops
  //* They can be as many levels deep as the program needs
  //* They are very useful with multi-dimensional data structures (2D, 3D arrays or vectors)
  //? Outer loop vs Inner loop

  //* For example

  /*
  for (outer_val = 1; outer_val <= 2; outer_val++) {
    for (inner_val = 1; inner_val <= 3; inner_val++) { //! While the outer loop is less than or equal to 2 the inner loop starts
      cout << outer_val << ", " << inner_val << endl; //! Displays the outer and inner values, the inner loop loops faster
    }
  }
  */

  //* First example (Προπαίδεια του 10)

  for (int num1 = 1; num1 <= 1; num1++) {
    for (int num2 = 1; num2 <= 10; num2++) {
      cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    }
  }

  //* Second example (Όλες οι προπαίδειες από το 0 μέχρι το 10)

  cout << endl << endl;

  for (int _num1 = 0; _num1 <= 10; _num1++) {
    for (int _num2 = 1; _num2 <= 10; _num2++) {
      cout << _num1 << " * " << _num2 << " = " << _num1 * _num2 << endl;
    }
    cout << "----------------" << endl;
  }

  //* Third example with 2D array

  int grid[5] [3] {}; // This is a 2D array which has 5 rows and 3 columns

  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 3; col++) {
      grid[row][col] = 1000; // Assigns each value in the array to 1000
    }
  }

  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 3; col++) {
      cout << grid[row][col] << " "; // Displays the values in the array
    }
    cout << endl; // Prints a new line after each row when the inner loop is completed
  }

  //* Fourth example with 2D vector

  vector<vector<int>> vec_2d {
    {1, 2, 3},
    {10, 20, 30, 40},
    {100, 200, 300, 400, 500}
  };

  for (auto vec: vec_2d) {
    for (auto val: vec) {
      cout << val << " "; // Displays the values in the vector
    }
    cout << endl; // Prints a new line after each row when the inner loop is completed
  }

  //* Last example

  int items {};

  cout << "How many data items do you have? ";
  cin >> items;

  vector<int> data {};

  for (int i = 1; i <= items; i++) {
    int data_item{};
    cout << "Enter data item " << i << ": ";
    cin >> data_item;
    data.push_back(data_item); // Adds each input to the vector
  }

  for (auto val: data) {
    for (int i = 1; i <= val; i++) {
      if (i % 5 == 0)
        cout << "*"; // Displays an asterisk every 5 dashes
      else
        cout << "-"; // Displays a dash for each value of each data item
    }
    cout << endl;
  }

  return 0;
}