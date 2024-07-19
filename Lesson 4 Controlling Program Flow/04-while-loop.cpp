#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
  //! While loop
  //? In while loops, iteratation happens while a condition remains true
  //? It stops when the condition becomes false
  //? Checks the condition at the beginning of every iteration

  //* For example

  /*
  while (expression)
    statement;

    or

  while (expression) {
    statement(s);
  }
  */

  //* First example

  int i {1};

  while (i <= 5) { // As long as i is less than or equal to 5 we continue execution.
    cout << i << endl;
    i++; //! Increment the counter by 1 after each iteration. Otherwise, the loop will not terminate.
  }

  //* Second example

  int j {1};
  cout << endl;

  while (j <= 10) {
    if (j % 2 == 0)
      cout << j << endl; // Displays the even numbers between 1 and 10
    j++;
  }

  //* Third example iteration through array

  int scores [] {100, 90, 87};
  i = 0;
  cout << endl;

  while (i < 3) { //! Be careful to not overflow the array
    cout << scores[i] << endl;
    i++;
  }

  //* Fourth example

  string password;
  cout << "Enter a password longer than 8 characters: ";
  cin >> password;

  while (password.length() < 8) { // Loops until the user enters a correct value
    cout << "Invalid input. Please enter a password longer than 8 characters: ";
    cin >> password;
  }
  cout << "Password accepted." << endl;

  //* Fifth example

  int number;
  cout << "Enter a number between 1 and 10: ";
  cin >> number;

  while (number < 1 || number > 10) {
    cout << "Invalid number. Please enter a number between 1 and 10: ";
    cin >> number;
  }

  //* Sixth example, same with the above but using booleans so it can only happen once(if we had a save file)

  bool done = false;
  number = 0;

  while (!done) {
    cout << "Enter a number between 1 and 10: ";
    cin >> number;
    if (number < 1 || number > 10) {
      cout << "Invalid number. Please enter a number between 1 and 10: ";
    } else {
      done = true;
      cout << "Number accepted." << endl;
    }
  }

  //* Seventh example

  number;
  done = false;

  while (!done) {
    cout << "Enter a positive number: ";
    cin >> number;
    if (number <= 0) {
      cout << number << " is not a positive number! " << endl;
    } else {
      while (number > 0) { // Counts down from the number given to 0 and displays it
        cout << number << endl;
        number--;
        done = true;
      }
    }
  }

  //* Eighth example

  number;
  i = 1;
  done = false;

  while (!done) {
    cout << "Enter a positive number to count up to: ";
    cin >> number;
    if (number <= 0) {
      cout << number << " is not a positive number! " << endl;
    } else {
      while (number >= i) { // Counts up from 1 to the number given and displays it
        cout << i << endl;
        i++;
        done = true;
      }
    }
  }

  //! This makes a nice shape with asterisks

  /*
  int balls = 1;
  int n = 15;
  while (balls < 5) {
      for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        cout << "*";
      }
      cout << endl;
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cout << "*";
      }
      cout << endl;
    }
    balls++;
  }
  */

  return 0;
}