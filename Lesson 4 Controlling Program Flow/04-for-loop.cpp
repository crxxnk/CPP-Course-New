#include <iostream>
#include <vector>

using namespace std;

int main() {
  //! For loop 
  //? In for loops we iterate a specific number of times

  //* For Example

  /*
  for (initialization; condition; increment)
    statement;

    !or
  
  for (initialization; condition; increment) {
    statement;
    statement;
  }
  */

  //* Example
  //? This program counts up to 5
  int i; //! We need to declare a variable for a loop so it can incremented or decremented, we usually call it i.
  for (i = 1; i <= 5; i++) { // Firstly we assign i to 1. Then we check if i is less than or equal to 5. If this is true, it increments i by 1.
    cout << i << endl;
  }

  //! It's better if we declare i inside the loop:
  for (int i = 1; i <= 10; i++) {
    if (i % 2 != 0) {
      cout << i << endl; // This will only display the odd numbers between 1 and 10.
    }
  }

  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
      cout << i << endl; // This will only display the even numbers between 1 and 10.
    }
  }

  //* Second example with arrays

  int scores [] {100, 90, 87, 85, 74};

  for (int i = 0; i < 5; i++) { // Checks if i is lees than 5 which is the index of the array. While this is true, it increments i by 1.
    cout << scores[i] << endl; // Assigns the variable i as the index in the array.
  }

  //! We can also write it like this (replace the i < 5 with i <= 4, it's the same thing):

  for (int i = 0; i <= 4; i++) {
    cout << scores[i] << endl; 
  }

  //* Third example with comma operator

  for (int i = 1, j = 5; i < 5; i++, j++) { // Creates 2 variables using commas and assigns them, then checks if i < 5. While true, it increments i and j by 1.
    cout << i << " * " << j << " : " << (i * j) << endl; // Calculates the multiplication and displays the result of i * j.
  }

  //* Another similar example

  for (int i = 1, j = 10; i < 10; i++) {
    cout << i << " * " << j << " : " << (i * j) << endl;
  }

  //* Fourth example

  for (int i = 10; i > 0; i--) {
    cout << i << endl; // This will display the numbers from 10 to 1.
  }

  //* Fifth example

  for (int i = 10; i <= 100; i+=10) {
    if (i % 15 == 0) {
      cout << i << " is divisible by 15" << endl; // This will display the numbers that can be divided by 15
    }
  }

  //* Sixth example

  for (int i = 50, j = 10; i > 0; i/=2) {
    cout << i * j << endl;
  }
  
  //* Seventh example

  for (int i = 1; i <= 100; i++) {
    cout << i;
    (i % 10 == 0) ? cout << endl : cout << " ";
  }

  //* Last example with vectors

  vector<int> numbers = {10, 20, 30, 40, 50};
  for (unsigned int i = 0; i < numbers.size(); i++) { // We make the int assigned because we are comparing with the size of a vector which can't be negative.
    cout << numbers[i] << endl;
  }

  //! Endless loop

  /*
  for (;;) {
    cout << "Endless loop" << endl;
  }
  */

  return 0;
}