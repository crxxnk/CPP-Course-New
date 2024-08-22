#include <iostream>

using namespace std;

/*
! Passing Arrays To Functions
? We can pass an array to a function by providing square brackets in the formal parameter description

void printArray(int numbers[])
{
  ! Doesn't know how many elements are in the array
  ! We need to pass in the size!
}

? The array elements are NOT copied
? Since the array name evaluates to the location of the array in memory - this address is what is copied
? So the function has no idea how many elements are in the array since all it knows is the location of the first element(the name of the array)
*/

//* Example:

void printArray(int numbers[], size_t size)
{
  for (size_t i = 0; i < size; i++)
    cout << numbers[i] << endl;
}

//* Since we are passing the location of the array, the function can modify the actual array
//! A good idea is to make the array constant

void zeroArray(int numbers[], size_t size)
{
  for (size_t i = 0; i < size; i++)
    numbers[i] = 0;
}

int main()
{
  int myNumbers[] {1,2,3,4,5};
  printArray(myNumbers, 5);
  zeroArray(myNumbers, 5); // myNumbers is now zeros because it has been modified by the function
  printArray(myNumbers, 5); // 0 0 0 0 0

  return 0;
}