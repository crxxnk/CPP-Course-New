#include <iostream>
#include <string>

using namespace std;

int main() {
  //! C++ strings are contiguous in memory and they have dynamic size, so we can change it any time unlike C style strings.
  //? For C++ strings functions we need to #include <string>.

  //* C++ strings initialization examples

  /*
  string s1; // Empty
  string s2 {"Alex"}; // Alex
  string s3 = s2; // Alex
  string s4 {"Alex", 3}; // It returns the first 3 letters so, Ale
  ! 0 is the starting index and 2 is the length
  string s5 {s3, 0, 2}; // Al
  ! Uses parenthesis
  string s6 (3, 'X'); // XXX
  */

  //* Assignment

  string s1;
  s1 = "C++ is fire";

  string s2 {"Hello"};
  s2 = s1;

  string part1 {"C++"};
  string part2 {"is a powerful"};

  string sentence;

  //! Concatenation
  sentence = part1 + " " + part2 + " language"; // C++ is a powerful language
  //sentence = "C++" + " is powerful"; //! Illegal

  //* Accessing characters

  string name {"Alex"};

  //? These are the same thing
  cout << name[0] << endl;
  cout << name.at(0) << endl;

  //* Changing characters

  name[0] = 'a';
  name.at(1) = 'b';

  cout << name << endl;

  //* Display characters one at a time

  string pet {"Dog"};

  for (char Pet: pet) {
    cout << Pet << endl;
  }

  //* Display them in ASCII format

  for (int Pet: pet) { // We change the variable to an int
    cout << Pet << endl;
  }

  //* Comparing

  string st1 {"Apple"};
  string st2 {"Banana"};
  string st3 {"Kiwi"};
  string st4 {"apple"};
  string st5 {st1};

  st1 == st5; // True
  st1 == st2; // False
  st1 != st2; // True
  st1 < st2; // True because Apple comes before Banana in the ASCII table
  st2 > st1; // True because Banana comes after Apple in the ASCII table
  st4 < st5; // False because apple with a lowercase 'a' comes after Apple in the ASCII table
  st1 == "Apple"; // True

  //* Substrings - substr()
  //? Extracts a substring from a string
  // object.substr(start_index, length)

  string test {"This is a test"};

  cout << test.substr(0, 4) << endl; // This
  cout << test.substr(5, 2) << endl; // is
  cout << test.substr(8, 1) << endl; // a
  cout << test.substr(10, 4) << endl; // test

  //* Searching - find()
  //? Returns the index from a substring in a string
  // object.find(search_string)

  cout << test.find("This") << endl; // Starts at index 0
  cout << test.find("is") << endl; // Starts at index 2
  cout << test.find("test") << endl; // Starts at index 10
  cout << test.find('e') << endl; // Found at index 11
  cout << test.find("is", 4) << endl; // Starts searching at index 4 so it returns 5
  cout << test.find("XX") << endl; // No position information available

  //! There is also an rfind() method. It is the same thing, but it starts searthing from the end of the string

  //* Removing characters - erase() and clear()
  //? Removes a substring of characters from a string
  // object.erase(start_index, length)

  cout << test.erase(0, 5) << endl; // is a test
  cout << test.erase(5, 4) << endl; // is a
  test.clear(); // Clears the string

  //* Other useful methods

  string frstName {"Alex"};
  cout << frstName.length() << endl; // 4
  frstName += " Rita";
  cout << frstName << endl; // Alex Rita

  //? And many more

  //* Input >> and getline()
  //? Reading string from cin
  
  string input; // Hello there
  /*
  cin >> input; //? Only accepts until the first whitespace
  cout << input << endl; //* Displays Hello
  */

  getline(cin, input); // Reads the entire line until \n
  cout << input << endl; // Displays Hello there

  //? We enter Hello therex
  getline(cin, input, 'x'); // Reads the entire line until x
  cout << input << endl; // Displays Hello there

  return 0;
}