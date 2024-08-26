#include <iostream>

using namespace std;

/*
! Scope Rules
? C++ uses scope rules to determine where an identifier can be used
? C++ uses static or lexical scoping
? Local or Block scope
? Global scope

! Local or Block scope
* Identifiers declared in a block { }
* Function parameters have block scope
* Only visible within the block { } where declared
* Function local variables are only active while the function is executing
* Local variables are NOT preserved between function calls
* With nested blocks inner blocks can 'see' but outer blocks cannot 'see' in

! Static local variables
* Declared with static qualifier
  static int value = 10;
* Value IS preserved between function calls
* Only initialized the first time the function is called

! Global scope
* Identifiers declared outside any function or class
* Visible to all parts of the program after the global identifier has been declared
* Global constants are OK
* Best practice - don't use global variables
*/

//* Examples:

void localExample(int x)
{
  int num = 1000;
  cout << "Local number is: " << num << endl;
  num = x;
  cout << "Local number changed to: " << num << endl;
}

void staticLocalExample()
{
  static int num = 5000; //! Initialized the first time the function is called
  cout << "Local static number is: " << num << endl;
  //! Will save this value to the actual variable so if we call the function again, the num will be 6000, 7000 etc.
  num+=1000;
  cout << "Local static number changed to: " << num << endl;
}

int main()
{
  int num = 100; // local to main
  int num1 = 500; // local to main
  cout << "Local number is: " << num << endl;
  
  { // creates a new level of scope
    int num = 200;
    cout << "Local number is: " << num << endl;
    cout << "Inner block in main can see out - num1 is: " << num1 << endl;
  }
  cout << endl;

  localExample(15);
  localExample(7000);
  cout << endl;
  staticLocalExample();
  staticLocalExample();

  return 0;
}