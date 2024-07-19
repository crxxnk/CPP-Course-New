#include <iostream>
#include <cstring>

using namespace std;

int main() {
  /*
  ! C-style Strings
  ? Sequence of characters
    * contiguous in memory
    * implemented as an array of characters
    * terminated by a null character (null)
      * null - character with a value of zero
    * Referred to as zero or null terminated strings
    
  ? String literal
    * sequence of characters in double quotes, e.g. "Alex"
    * constant
    * terminated with null character
  */

  //? For example if we have a string "C++ is fun", it is stored in the memore as
  //* C + +  i s  f u n \0 (null)

  //* C-style string initialization:

  char my_name[] {"Alex"};
  cout << "My name is: " << my_name << endl;
  // my_name[4] = 'e'; We cant add a character like this because it will not be null terminated and the string will be so weird
  //! To do that, we need to tell the compiler to allocate at least 2 more characters for the array so the null terminator can move forward
  char my_new_name[6] {"Alex"};
  my_new_name[4] = 'e';
  cout << "My new name is: " << my_new_name << endl;

  char cock[8];
  // cock = "Alex" //! Error
  strcpy(cock, "Alex"); // Correct way to copy string using strcpy function //* We need to include <cstring>
  cout << "My name is: " << cock << endl;

  //? cstring contains:
  //* Copying
  //* Concatenation
  //* Comparison
  //* Searching
  //* and others

  //* Examples

  char str[80];
  strcpy(str, "Hello "); // Copy
  strcat(str, "World"); // Concatenate (they connect so world is put next to hello)
  cout << strlen(str) << endl; // Shows the length of the string excluding the null terminator
  cout << str << endl; // Displays the string
  cout << strcmp(str, "Another"); // > 0

  //! #include <cstdlib>
  //? Includes functions to convert C-style strings to
  //* integers, float, long, etc.

  return 0;
}