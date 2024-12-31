#include <iostream>

/*
! Exception handling
  * Dealing with extraordinary situations
  * Indicates that an extraordinary situation has been detected or has occurred
  * Program can deal with the extraordinary situations in a suitable manner
? What causes exceptions?
  * Insufficient resources
  * Missing resources
  * Invalid operations
  * Range violations
  * Underflows and overflows
  * Illegal data and many others
? Exception safe
  * When your code handles exceptions

! Terminology
? Exception
  * An object or primitive type that signals that an error has occurred
? Throwing an exception (raising an exception)
  * Your code detects that an error has occurred or will occur
  * The place where the error occurred may not know how to handle the error
  * Code can throw an exception describing the error to another part of the program that knows how to handle the error
? Catching an exception (handle the exception)
  * Code that handles the exception
  * May or may not cause the program to terminate
throw
  * throws an exception
  * followed by an argument
try { code that may throw an exception }
  * you place code that may throw an exception in a try block
  * if the code throws an exception the try block is exited
  * the thrown exception is handled by a catch handler
  * if no catch handler exists the program terminates
catch(Exception ex) { code to handle the exception }
  * code that handles the exception
  * can have multiple catch handlers
  * may or may not cause the program to terminate
? What happens if total is zero?
  * crash, overflow?
  * it depends
double average;
average = sum / total;
* To fix it:
double average;
if(total == 0)
  what to do...
else
  average = sum / total;
? But what if there's a function that returns the average? (or sum like that)
double average;
try {
  if(total == 0)
    throw 0; //! throw the exception
  average = sum / total; // won't execute if total == 0
}
catch(int &ex) {
  std::cerr << "Can't divide by zero" << std::endl;
}
std::cout << "Program continues" << std::endl;
*/

/*
! Throwing an exception from a function
? What do we return if total is zero?
double calculate_avg(int sum, int total) {
  if(total == 0)
    throw 0;
  return static_cast<double>(sum) / total;
}

? Catching an exception thrown from a function
double average;
try {
  average = calculate_avg(sum, total);
  std::cout << average << std::endl;
}
catch (int &ex) {
  std::cerr << "You can't divide by zero" << std::endl;
}
*/

double calculate_avg(int sum, int total) {
  if(total == 0)
    throw 0;
  return static_cast<double>(sum) / total;
}

int main()
{
  int miles;
  int gallons;
  double miles_per_gallon;

  std::cout << "Enter the miles: ";
  std::cin >> miles;
  std::cout << "Enter the gallons: ";
  std::cin >> gallons;

  try {
    if(gallons == 0)
      throw 0;
    miles_per_gallon = static_cast<double>(miles) / gallons;
    std::cout << "Result: " << miles_per_gallon << std::endl;
  }
  catch(int &ex){
    std::cerr << "Can't divide by " << ex << std::endl;
  }

  //* Function example:

  int sum, total;
  std::cout << "Enter the sum: ";
  std::cin >> sum;
  std::cout << "Enter the total: ";
  std::cin >> total;

  double average;
  try {
    average = calculate_avg(sum, total);
    std::cout << average << std::endl;
  }
  catch (int &ex) {
    std::cerr << "Can't divide by zero" << std::endl;
  }

  return 0;
}