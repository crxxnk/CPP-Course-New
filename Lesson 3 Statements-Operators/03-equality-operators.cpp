#include <iostream>
#include <compare>

using namespace std;

int main() {
  /*
  ! Equality
  ? The == and != operators
  * Compares the values of 2 expressions
  * Evaluates to a Boolean (True or False, 1 or 0)
  * Commonly used in control flow statements
  
  expr1 == expr2
  expr1 != expr2
  100 == 200
  num1 != num2
  */

  bool result = false;
  result = (100 == 50 + 50);
  cout << boolalpha; // Makes the console display true or false instead of 1 or 0 or noboolalpha to go back to 1 or 0
  cout << result << endl;

  //? We can also compare any type of value
  bool equal_result = false;
  bool not_equal_result = false;
  char char1, char2;
  cin >> char1 >> char2;
  equal_result = (char1 == char2);
  not_equal_result = (char1 != char2);
  cout << "Comparison result (equals): " << equal_result << endl;
  cout << "Comparison result (not equals): " << not_equal_result << endl;

  return 0;
}