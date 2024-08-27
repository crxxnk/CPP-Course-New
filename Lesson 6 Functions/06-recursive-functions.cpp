#include <iostream>

using namespace std;

/*
! Recursive Functions
? A recursive function is a function that calls itself
  * Either direclty or indirectly through another function
? Recursive problem solving
  * Base case
  * Divide the rest of problem into subproblem and do recursive call
? There are many problems that lend themselves to recursive solutions
? Mathenatuc - factorial, Fibonacci, fractals,...
? Searching and sorting - binary search, search tress,...

! Important notes
? If recursion doesn't eventually stop you will have infinite recursion
? Recursion can be resource intensive
? Remember the base case(s)
  * It terminates the recursion
? Only use recursive solutions when it makes sense
? Anything that can be done recursively can be done iteratively
  * Stack overflow error
*/

/*
* Example - Calculate factorial number
0! = 1
n! = n * (n - 1)
* Base case:
  factorial(0) = 1
* Recursive case:
  factorial(n) = n * factorial(n - 1)
*/

unsigned long long factorial(unsigned long long n)
{
  if(n == 0)
    return 1; // Base case - Stops the recursion
  return n * factorial(n - 1); // Returns the result of calling the function again with n - 1
}

/*
* Example - Calculate Fibonacci number
Fib(0) = 0
Fib(1) = 1
Fib(n) = Fib(n - 1) + Fib(n - 2)
* Base case:
  Fib(0) = 0
  Fib(1) = 1
* Recursive case:
  Fib(n) = Fib(n - 1) + Fib(n - 2)
*/

unsigned long long Fib(unsigned long long n)
{
  if(n <= 1)
    return n;
  return Fib(n-1) + Fib(n-2);
}

int main()
{
  cout << factorial(8) << endl; // 40320
  cout << Fib(8) << endl; // 21

  return 0;
}