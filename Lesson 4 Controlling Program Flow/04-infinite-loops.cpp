#include <iostream>

using namespace std;

int main() {
  /*
  ! Infinite loops
  ? They are loops whose condition expression always evaluates to true
  ? Usually, this is unintended and a programmer error
  ? Sometimes, programmers use infinite loops and include break statements in the body to control them
  ? Sometimes, infinite loops are exactly what we need
    * Event loop in an event-driven program
    * Operating system
  */

  //* For example
  
  for (;;) {
    cout << "This program will print forever!" << endl;
  }

  //* Example with a while loop

  while (true) {
    cout << "This program will print forever!" << endl;
  }

  //* Example with a do-while loop

  do {
    cout << "This program will print forever!" << endl;
  } while (true);

  //* Useful example with an infinite loop

  while (true) {
    char again;
    cout << "Do you want to try again? ";
    cin >> again;

    if (again == 'N' || again == 'n') {
      break;
    }
  }

  return 0;
}