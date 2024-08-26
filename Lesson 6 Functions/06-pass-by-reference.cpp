#include <iostream>
#include <vector>

using namespace std;

/*
! Pass by Reference
? Sometimes we want to be able to change the actual parameter from within the function body
? In order to achieve this we need the location or address of the actual parameter
? We saw how this is the effect with array, but what about other variable types?
? We can use reference parameters to tell the compiler to pass in a reference to the actual parameter
? The formal parameter will now be an alias for the actual parameter
*/

//* Examples:

void scaleNumber(int &num)
{
  if (num > 100)
    num = 100; //! Changes the actual variable
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

/*
! If we want to use vector parameters, we mostly need to pass by reference,
!  in order to prevent performance issues caused by the vector being too big or so
void print(vector<int> v)
{
  for(auto num: v)
    cout << num << endl;
}
*/

//! As long as we are not changing any values we should make the variable a constant
void print(const vector<int> &v) //* Same function as the above but passing by reference
{
  for(auto num: v)
    cout << num << endl;
}

int main()
{
  int number = 1000;
  scaleNumber(number); // Changes the number variable to 100
  cout << "Scaled number: " << number << endl;

  int x = 10, y = 20;
  cout << x << " " << y << endl;
  swap(x, y); // Swaps the values of x and y
  cout << x << " " << y << endl;

  vector<int> data {1,2,3,4,5};
  print(data);

  return 0;
}