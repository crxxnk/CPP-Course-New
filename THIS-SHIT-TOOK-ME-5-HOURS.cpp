#include <iostream>
#include <vector>

using namespace std;

bool lastDig(int a, int b, int c) {
	if ((a * b) == (c % 10)) { // checks if the multiplication is equal to the last digit of c //! IT TOOK ME 5 FUCKING HOURS
		return true;
	} else {
    return false;
  }
}

int main() {
  if (lastDig(5, 1, 2525) == 0) {
    cout << "False" << endl;
  } else {
    cout << "True" << endl;
  }

  return 0;
}