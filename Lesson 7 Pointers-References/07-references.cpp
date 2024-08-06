#include <iostream>
#include <vector>

using namespace std;

int main() {
  /*
  ? What is a reference?
  * An alias for a variable
  * Must be initialized to a variable when declared
  ! Cannot be null
  * Once initialized, cannot be made to refer to a different variable
  * Very useful as function parameters
  * Might be helpful to think of a reference as a constant pointer that is automatically dereferenced
  */

  //* Using references in range-based for loops

  //! THIS RANGE-BASED FOR LOOP DOES NOT USE REFERENCES
  vector<string> stooges {"Larry", "Moe", "Curly"};
  for (auto stooge: stooges)
    stooge = "Funny"; //! Even though we change every element to Funny, it is stored in a termporary variable called stooge!

  for (auto stooge: stooges)
    cout << stooge << endl; //! It displays every element in the vector without changing them to Funny as we saw above. We can do it with references!

  //? Actually using references:
  for (auto &stooge: stooges) //! We use the memory operator
    stooge = "Funny";

  for (auto const stooge: stooges)
    cout << stooge << endl; //! It displays Funny for every element in the vector, makes sense to make it constant.

  /*
  for (auto const &stooge: stooges)
    stooge = "Funny"; //! Compiler error
  */

  //* Examples

  int num = 100;
  int &numRef = num;

  //? Displaying the number or the number reference is exactly the same
  cout << num << endl;
  cout << numRef << endl;

  num = 200;
  cout << num << endl;
  cout << numRef << endl;

  numRef = 300;
  cout << num << endl;
  cout << numRef << endl;

  return 0;
}