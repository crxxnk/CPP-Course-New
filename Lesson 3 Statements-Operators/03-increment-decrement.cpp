#include <iostream>

using namespace std;

int main() {
  //* Increment operator ++
  //* Decrement operator --

  //! These two are exactly the same thing but only when the postfix is alone on the line!
  //? Prefix ++num
  //? Postfix num++

  //* First example
  int counter = 10;
  int result = 0;

  cout << "Counter: " << counter << endl;

  counter = counter + 1;
  cout << "Counter: " << counter << endl;

  counter++; // This is the same as counter = counter + 1
  cout << "Counter: " << counter << endl;

  ++counter;
  cout << "Counter: " << counter << endl;

  //* Second example

  counter = 10;
  result = 0;

  cout << "Counter: " << counter << endl;

  //? Uses preincrement so it adds one to the counter variable before it stores it in result, 
  //? otherwise the result would be 10 and the counter 11
  result = ++counter;
  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  //* Third example

  counter = 10;
  result = 0;

  cout << "Counter: " << counter << endl;

  //? Uses preincrement so it firstly adds one to the counter variable, 
  //? after that it stores it in the result and adds 10 to it
  result = ++counter + 10; 

  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  //* Fourth example

  counter = 10;
  result = 0;

  result = counter++ + 10;

  cout << "Counter: " << counter << endl;
  cout << "Result: " << result << endl;

  return 0;
}