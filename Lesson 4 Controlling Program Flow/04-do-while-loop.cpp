#include <iostream>

using namespace std;

int main() {
  //! Do while loop
  //? Runs some code first and then repeats it based on the while statement
  //? It checks the condition at the end of each loop

  //* For example

  /*
  do {
  statements;
  } while (expression);
  */

  //* Example

  int num;

  do {
    cout << "Enter a number from 1 to 10: ";
    cin >> num;
  } while (num <= 0 || num > 10); // Checks if the number is less than or equal to 0 or greater than 10. If true, it continues repeating the loop

  cout << "You entered: " << num << endl;

  //* Second example

  char selection;

  do {
    double width, height; // We can declare variables within the do statement
    cout << "Enter the width and height of a separated by a space: ";
    cin >> width >> height;

    double area = width * height;
    cout << "The area of is: " << area << endl;

    cout << "Do you want to calculate another? (Y/N) : ";
    cin >> selection;
    cout << endl;
  } while (selection == 'Y' || selection == 'y');  // Checks if the user entered Y or y. If true, it continues repeating the loop

  //* Third example

  do {
    cout << "1. Do this" << endl;
    cout << "2. Do that" << endl;
    cout << "3. Do something else" << endl; // Displays these messages the first time the program runs
    cout << "Q. Quit" << endl << endl;
    cout << "Enter your selection: ";
    cin >> selection;
    cout << endl;

    if (selection == '1') {
      cout << "Doing this" << endl << endl;
    } else if (selection == '2') {
      cout << "Doing that" << endl << endl;
    } else if (selection == '3') {
      cout << "Doing something else" << endl << endl;
    } else if (selection == 'Q' || selection == 'q') {
      cout << "Goodbye!";
    } else {
      cout << "Invalid selection. Please try again." << endl << endl;
    }
  } while (selection != 'Q' && selection != 'q');

  return 0;
}