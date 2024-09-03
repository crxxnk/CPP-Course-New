#include <iostream>

using namespace std;

/*
! Structs vs Classes
? In addition to define a class we can declare a struct
? struct comes from the C programming language
? Essentially the same as a class expect
  * members are public by default

class Person
{
  string name;
  string getName();
};

Person p;
p.name = "Alex"; //! Compiler error - private
cout << p.getName() << endl; //! Compiler error - private
*/

struct Person
{
  string name;
  // string getName(); No need to use it while name is public
};

/*
! Some general guidelines
? struct
  * Use struct for passive objects with public access
  * Don't declare methods in struct

? class
  * Use class for active objects with private access
  * Implement getters/setters as needed
  * Implement member methods as needed
*/

int main()
{
  Person p;
  p.name = "Alex";

  return 0;
}