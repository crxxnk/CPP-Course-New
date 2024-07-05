#include <iostream>

using namespace std;

int main() {
  //! Switch statements
  //? Switch statements are like if-else statements
  //? We use them to prevent using many if-else statements
  //! The expression MUST have an integral or enum type
  //! The case expressions MUST be known at compile time so only literals and constants can be used, not variables
  //* Syntax
  /*
  switch (integer_control_expr) {
    case expression_1: statement_1; break;
    case expression_2: statement_2; break;
    case expression_3: statement_3; break;
    ...
    case expression_n: statement_n; break;
    default: default_statement;
  }
  */

  //* Example
  char selection;
  cout << "Enter a character: ";
  cin >> selection;

  switch (selection) {
    //? If selection == '1' it outputs 1 selected, if selection == '2' it outputs 2 selected...
    case '1': cout << "1 selected";
    break; //! Completes the switch statement. No further cases will be checked and the program continues.
    case '2': cout << "2 selected";
    break;
    case '3': //! This is like an OR statement, it checks if selection == '3' || selection == '4'.
    case '4': cout << "3 or 4 selected";
    break;
    default: cout << "1, 2, 3, 4 NOT selected"; //! If none of the previous case statements match, the default statement is executed.
  }

  switch (selection) {
    //* In this case we don't use break statements, that means if the user selects '1',
    //* it will output 1 selected but the switch will continue until it hits the break statement.
    //! So it will also display 2 selected and 3 or 4 selected even if they don't match.
    //! It stops at 3 or 4 selected because ther is a break statement
    /*
    case '1': cout << "1 selected";
    case '2': cout << "2 selected";
    case '3':
    case '4': cout << "3 or 4 selected";
    break;
    default: cout << "1, 2, 3, 4 NOT selected";
    */
  }

  //! Switch statement with enumeration (we will learn about enums later)
  enum Color {
    red, green, blue
  };
  Color screen_color = green; // Creates a variable called screen_color of the type Color which is the enumeration. It is equal to green in the Color enum.
  cout << endl; // Ignore this, it just makes a new line cause I forgot to do it before
  switch (screen_color) {
    case red: cout << "red"; break;
    case green: cout << "green"; break;
    case blue: cout << "blue"; break;
    default: cout << "Should never execute";
  }

  //! We can't use strings for example as an expression because they aren't an integral type
  /*
  string cock = "balls";
  switch (cock) {
    case "balls": cout << "balls"; break;
    case "butt": cout << "butt"; break;
  }
  */

  //* Practice

  cout << endl;

  char letter_grade;
  cout << "What grade do you expect to get in the exam? ";
  cin >> letter_grade;

  switch (letter_grade) {
    case 'A':
    case 'a': cout << "You need 90 or above for an A!" << endl; 
    break;
    case 'B':
    case 'b': cout << "You need 80 - 89 for a B!" << endl; 
    break;
    case 'C':
    case 'c': cout << "You need 70 - 79 for a C!" << endl; 
    break;
    case 'D':
    case 'd': cout << "You need 60 - 69 for a D!" << endl; 
    break;
    case 'F':
    case 'f':
    {
      char confirm; //! We need the curly braces in the f case just because we are declaring a variable
      cout << "Are you sure you want to fail this exam? (Y/N): ";
      cin >> confirm;
      if (confirm == 'y' || confirm == 'Y') {
        cout << "That's sad." << endl;
      } else if (confirm == 'n' || confirm == 'N') {
        cout << "Then go study!" << endl;
      } else {
        cout << "Illegal choice" << endl;
      }
    }
    break;
    default: cout << "Sorry, not a valid grade!" << endl;
  }

  //* Second practice

  enum Direction {
    right, left, up, down
  };

  Direction heading = left; // Creates a variable called heading of the type Direction (the enum)

  switch (heading) {
    case right: cout << "You are facing right." << endl; break;
    case left: cout << "You are facing left." << endl; break;
    case up: cout << "You are facing up." << endl; break;
    case down: cout << "You are facing down." << endl; break;
    default: cout << "Invalid direction." << endl; break;
  }

  return 0;
}