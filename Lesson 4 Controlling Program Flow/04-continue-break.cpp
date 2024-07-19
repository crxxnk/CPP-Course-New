#include <iostream>
#include <vector>

using namespace std;

int main() {
  /*
  ! Continue and break

  ? Continue

  * No further statements in the body of the loop will be executed.
  * Control immediately goes directly to the beginning of the loop for the next iteration.
  
  ? Break

  * No further statements in the body of the loop will be executed.
  * Loop is immediately terminated.
  * Control immediately goes to the following statement.
  */

  //* Example

  vector<int> values {1, 2, -1, 3, -1, -99, 7, 8, 10}; // If -99 wasn't here, all the numbers would be shown except for the negative ones, because we continue when we find -1
  for (auto val: values) {
    if (val == -99) // Checks if the value is -99. If true, the for loop terminates
      break;
    else if (val == -1) // Checks if the value is -1. If true, the for loop goes back to the beginning
      continue;
    else
      cout << val << endl;
  }

  return 0;
}