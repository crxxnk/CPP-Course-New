#include <iostream>

using namespace std;

int main() {
  //! If statement
  //? If a condition is true, execute some code
  // if (expr)
  // statement; 

  //? We don't need curly braces if the statement is only one line of code
  //* For example

  int num = 20;
  if (num > 10)
    ++num;

  cout << num << endl;

  //? If we want to have a statement with more than one line of code we use {}
  //* For example

  int num2 = 12;
  if (num2 > 10) {
    ++num2;
    cout << num2 << endl;
  }

  //! Block statement
  //? We create a block of code by including more than one statement in code block {}
  //? Blocks can also contain variable declarations
  //! These variables are only visible within the block - local scope
  //* For example

  {
    // variable declarations
    // statement1;
    // statement2;
    //...
  }

  //* Practice

  int number;
  const int min {10};
  const int max {100};

  cout << "Enter a number between " << min << " and " << max << ": ";
  cin >> number;

  if (number >= min) {
    cout << number << " is greater than or equal to " << min << endl;

    int diff {number - min};
    cout << "The difference between " << number << " and " << min << " is " << diff << endl;
  }

  if (number <= max) {
    cout << number << " is less than or equal to " << max << endl;

    int diff {max - number};
    cout << "The difference between " << max << " and " << number << " is " << diff << endl;
  }

  if (number >= min && number <= max) {
    cout << number << " is in range" << endl;
    cout << "This means that the first and second statements should also display!" << endl;
  }

  if (number == min || number == max) {
    cout << number << " is right on boundary" << endl;
    cout << "This means that all 4 statements should display!" << endl;
  }

  return 0;
}