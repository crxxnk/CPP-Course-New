#include <iostream>

using namespace std;

int main() {
  //! Conditional operator
  //? The conditional operator is like an if statement but with much less typing
  //* For example

  // (cond_expr) ? expr1 : expr2 //! If cond_expr is true then expr1 is returned, else expr2 is returned
  //! ? represents if and : represents else

  //* Example

  int a = 10;
  int b = 20;
  int score = 92;
  int result;

  result = (a > b) ? a : b; // If a is greater than b, store a in the variable, else store b in the variable
  result = (a < b) ? (b-a) : (a-b); // If a is less than b, store b-a in the variable, else store a-b in the variable
  result = (b != 0) ? (a/b) : 0; // If b does not equal to 0, store a/b in the variable, else store 0 in the variable

  //! We need to include parenthesis or it will just display 1 or 0 (true or false)
  cout << ((score > 90) ? "Excellent" : "Good") << endl; // If score is greater than 90, it returns "Excellent" and displays it, else it returns "Good"

  //* Second example

  int num;
  cout << "Enter a number: ";
  cin >> num;
  cout << num << " is " << ((num % 2 == 0) ? "even" : "odd") << endl; // % is the remainder of the division of 2 numbers

  //* Third example

  int num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  if (num1 != num2) {
    cout << "Larger: " << ((num1 > num2) ? num1 : num2) << endl;
    cout << "Smaller: " << ((num1 < num2) ? num1 : num2) << endl;
  } else {
    cout << "The numbers are equal." << endl;
  }

  return 0;
}