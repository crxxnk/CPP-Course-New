#include <string>

using namespace std;

int main() {
  /*
  ? L values
  * values that have names and are addressable
  * modifiable if they are not constants
  */

  int x {100}; // x is an l value
  x = 1000;
  x = 1000 + 20;

  string name; // name is an l value
  name = "Alex";

  /*
  100 = x; //! 100 is NOT an l value
  (1000 + 20) = x; //! (1000 + 20) is NOT an l value

  "Alex" = name; //! "Alex" is NOT an l value
  */

  /*
  ? R values (non-addressable and non-assignable)
  * A value that's not an l-value
  * on the right-hand side of an assignment expression
  * a literal
  * a temporary which is intended to be non-modifiable
  */
  int a {100}; // 100 is an r-value
  int y = a + 200; // (a+200) is an r-value

  string str;
  str = "Alex"; // "Alex" is an r-value
  
  int max_num = max(20,30); // max(20,30) is an r-value

  //* r-value can be assigned to l-values explicitly
  int b {100};
  int c {0};

  c = 100; // r-value 100 assigned to l-value c
  b = b + c; // r-value (b+c) assigned to l-value b

  /*
  ? l-value references
  * The references we've used are l-value references
  * Because we are referencing l-values
  */
  int xx {100};

  int &ref1 = xx; // ref1 is reference to l-value
  ref1 = 1000;

  //int &ref = 100; //! ERROR - 100 is an r-value

  /*
  ! The same when we pass-by-reference

  int square(int &n) {
    return n*n;
  }

  int num {10};
  square(num); // OK
  square(5) //! ERROR - can't reference r-value 5
  */

  return 0;
}