#include <iostream>

using namespace std;

int main() {
  /*
  ! I SHOULD LOOK AT COMPLETE OPERATOR PRESEDENCE AT https://en.cppreference.com/w/cpp/language/operator_precedence
  ! Logical operators
  * !(not) negation
  * && (and) logical and
  * || (or) logical or
  
  ? For example if expression a is true, then !a is false.
  ? Otherwise if expression a is false, then !a is true.

  ? If expression a is true and expression b is true, a && b is true.
  ? Otherwise if expression a is true and expression b is false, a && b is false.
  ? If expression a is false and expression b is false, a && b is true.
  ? Otherwise if expression a is false and expression b is true, a && b is false.

  ? If expression a is true or expression b is true, a || b is true.
  ? Otherwise if expression a is true or expression b is false, a || b is true.
  ? If expression a is false and expression b is true, a || b is true.
  ? Otherwise if expression a is false or expression b is false, a || b is false.

  ! Priority in logical operators
  * Not has higher priority than and
  * And has higher priority than or
  */

  int num;
  const int lower {10}; // It's the same as using equals. I just used {}
  const int upper {20};
  bool within_bounds {false};

  cout << boolalpha;
  cout << "Enter an integer between the bounds " << lower << " and " << upper << ": ";
  cin >> num;

  within_bounds = (num >= lower && num <= upper);
  cout << "Is the number " << num << " within the bounds " << lower << " and " << upper << "? " << within_bounds << endl;

  int num2;
  bool outside_bounds {false};

  cout << "Enter an integer between the bounds " << lower << " and " << upper << ": ";
  cin >> num2;

  outside_bounds = (num2 < lower || num2 > upper);
  cout << "Is the number " << num2 << " outside the bounds " << lower << " and " << upper << "? " << outside_bounds << endl;

  return 0;
}