#include <iostream>
#include <cctype> // We can include cctype to get access to some useful functions

using namespace std;

int main() {
  //! Character functions
  //* All the character functions expect a single character for input
  //? There are functions for testing characters | They return true or false
  //? And functions for converting character case | They return the converted character
  //! To use these functions we must include cctype

  //* Testing character functions:

  char c = 'a';
  isalpha(c); // Returns true if c is a letter
  isalnum(c); // Returns true if c is a letter or digit
  isdigit(c); // Returns true if c is a digit
  islower(c); // Returns true if c is a lowercase letter
  isupper(c); // Returns true if c is an uppercase letter
  isprint(c); // Returns true if c is a printable character
  ispunct(c); // Returns true if c is a punctuation character
  isspace(c); // Returns true if c is a whitespace character

  //* Example

  char test;
  cout << "Please enter a character: ";
  cin >> test;

  isalpha(test) ? cout << "Your character is a letter" << endl : isalnum(test) ? cout << "Your character is a digit" << endl : cout << "You are gay" << endl;

  //* Converting character functions:

  tolower('A'); // Returns the lowercase of A
  toupper('a'); // Returns the uppercase of a

  //* Example

  char letter;
  cout << "Enter a letter: ";
  cin >> letter;

  // For some reason they evaluate to a number
  if (islower(letter))
    cout << "Converted letter: " << toupper(letter);
  else 
    cout << "Converted letter: " << tolower(letter);

  return 0;
}