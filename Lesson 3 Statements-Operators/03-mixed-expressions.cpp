#include <iostream>

using namespace std;

int main() {
  //! Excplicit type casting - static_cast<type>

  int total_amount = 100;
  int total_number = 8;
  double average = 0.0;

  average = total_amount / total_number;
  cout << average << endl; // Rounds the number and displays 12

  //? To fix that we use the explicit type casting to convert an int to a double
  //* If we convert at least one int to a double, the compiler will automatically do double division instead of int division
  average = static_cast<double>(total_amount) / total_number;
  cout << average << endl; // Displays 12.5

  //! We can also do the opposite but the way we did it above is more visible
  // average = total_amount / static_cast<double>(total_number);

  //************** Example **************

  int total;
  int num1, num2, num3;
  const int count = 3;

  cout << "Please enter 3 integers: " << endl;
  cin >> num1 >> num2 >> num3;

  total = num1 + num2 + num3;

  double _average = 0.0;

  _average = static_cast<double>(total) / count;
  // average = (double)total/count; Old style

  cout << "The 3 numbers you entered are: " << num1 << ", " << num2 << ", " << num3 << endl;
  cout << "The sum of the numbers is: " << total << endl;
  cout << "Average: " << _average << endl;

  return 0;
}