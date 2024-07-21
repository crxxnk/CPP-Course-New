#include <iostream>
#include <cstring> // for c-style string functions
#include <cctype> // for character-based functions

using namespace std;

int main() {
  char first_name[20] {};
  char last_name[20] {};
  char full_name[50] {};
  char temp[50] {};

  cout << first_name << endl; // Will likely display garbage

  cout << "Please enter your first name: ";
  cin >> first_name;

  cout << "Please enter your last name: ";
  cin >> last_name;
  cout << "--------------------------------------" << endl;

  //! Instead of returning an int, the strlen function returns a size_t value which is an unsigned value we don't know(unsigned long, unsigned long long)
  cout << "Hello " << first_name << " your first name has " << strlen(first_name) << " characters" << endl;
  cout << "and your last name " << last_name << " has " strlen(last_name) << " characters" << endl;

  strcpy(full_name, first_name); // Copies the first_name to the full_name variable
  strcat(full_name, " "); // Adds a space to the full_name variable
  strcat(full_name, last_name); // Adds the last_name to the full_name variable

  cout << "Your full name is " << full_name << endl;

  /*
  ! If we actually enter our full name, the compiler will stop the output whenever it sees a whitespace so it would only display the first name
  cout << "Enter your full name: ";
  cin >> full_name;
  cout << "Your full name is " << full_name << endl; 
  */

  //? Instead, we do this:

  cout << "Enter your full name: ";
  cin.getline(full_name, 50); // Max characters are 50. It stops when it reaches 50 chars or when the user presses enter
  cout << "Your full name is " << full_name << endl;

  return 0;
}