#include <iostream>

using namespace std;

//! We calculate the values by using the number of bits as the power of 2.
//* 8 bits can store up to 256 values(2^8).
//* 16 bits can store up to 65.536 values(2^16).
//* 32 bits can store up to 4.294.967.296 values(2^32).
//* 64 bits can store up to 18.446.744.073.709.551.615 values(2^64).
int main() {
  //char //? at least 8 bits
  //char16_t //? at least 16 bits
  //char32_t //? at least 32 bits
  //wchar_t //? Largest available character set
  
  //! Signed integers hold all numbers.
  //* Integers are signed by default so we don't need to use this keyword.
  //signed short int //? at least 16 bits
  //signed int //? at least 16 bits
  //signed long int //? at least 32 bits
  //signed long long int //? at least 64 bits

  //! Unsigned integers hold only positive numbers and 0.
  //unsigned short int //? at least 16 bits
  //unsigned int //? at least 16 bits
  //unsigned long int //? at least 32 bits
  //unsigned long long int //? at least 64 bits
  //* We can also write unsigned short "name" = value; (we don't need to write the word int) and it's the same with all the others.
  //? For example
  long /*<- signed long int*/ greecePopulation = 10430000;
  cout << "Greece's population is " << greecePopulation << " people." << endl;

  //! If a number is huge and may not fit in a long, it's better if we use list initialization,
  //! so the compiler can catch the error and we won't get a false result:
  //long veryLargeNumber = 1000000000000000000; //? Gives a warning and displays a false result.
  //long veryLargeNumber {1000000000000000000}; //! Causes an error and doesn't display anything.
  long long veryLargeNumber = 1000000000000000000; //* The initialization doesn't matter if we are using a long long int(as long as the number is not huge huge).
  cout << "Very large number: " << veryLargeNumber << endl;

  //float //? 7 decimal digits
  //double //? 15 decimal digits
  //long double //? 19 decimal digits

  //bool //? 8 bits
  //* True or false.
  //* 0 is false, non-zero is true.

  return 0;
}