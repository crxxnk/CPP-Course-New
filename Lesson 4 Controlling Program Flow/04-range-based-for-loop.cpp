#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  //! Range-based for loops
  //? In range-based for loops we do one iteration for each element in a range or collection

  //* For example

  /*
  for (var_type var_name: sequence)
    statement;

    !or

  for (var_type var_name: sequence) {
    statements;
  }
  */

  //* Example

  int scores [] = {100, 97, 90};

  for (int score : scores) { // We can also use auto instead of int to let the compiler pick the variable type.
    cout << score << endl; // Displays every element in the scores array.
  }

  //* Second example

  vector<double> temps {87.2, 70.9, 85.1, 69.4};

  double average_temp;
  double temp_sum;

  for (auto temp: temps) {
    temp_sum += temp; // Adds each temperature to the sum.
  }

  cout << fixed << setprecision(1);
  average_temp = temp_sum / temps.size();
  cout << "Temperature sum: " << temp_sum << endl;
  cout << "Average temperature: " << average_temp << endl;

  //! This is the same thing as the above but we don't usually use that
  
  /*
  double average_temp;
  double temp_sum;
  int size = 0;

  for (auto temp: {87.2, 70.9, 85.1, 69.4}) {
    temp_sum += temp; // Adds each temperature to the sum.
    size++; // Keeps track of the number of elements.
  }
  average_temp = temp_sum / size;
  cout << "Temperature sum: " << temp_sum << endl;
  cout << "Average temperature: " << average_temp << endl;
  */

  //* Fourth example

  for (auto c: "This is a test") {
    if (c != ' ') {
      cout << c; // Prints every character in the string excluding spaces.
    }
  }
  

  return 0;
}