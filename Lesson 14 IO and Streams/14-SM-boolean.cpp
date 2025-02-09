/*
! Formatting boolean types
? Default when displaying boolean values is 1 or 0
? Sometimes the strings true or false are more appropriate

std::cout << (10 == 10) << std::endl;
std::cout << (10 == 20) << std::endl;
Will display
1
0

! std::cout << std::boolalpha
std::cout << (10 == 10) << std::endl;
std::cout << (10 == 20) << std::endl;
Will display
true
false

! All further boolean output will be affected
std::cout << std::noboolalpha; // 1 or 0
std::cout << std::boolalpha; // true or false

* Method version
std::cout.setf(std::ios::boolalpha);
std::cout.setf(std::ios::noboolalpha);

* Reset to default
std::cout << std::resetiosflags(std::ios::boolalpha);
*/
#include <iostream>
#include <iomanip>

int main() {
  std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

  std::cout << std::boolalpha; // Set to true/false formatting
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;
  
  // Setting still stays for future boolean insertions
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

  // Toggle 0/1
  std::cout << std::noboolalpha;
  std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;
  
  // Set back to true/false using setf method
  std::cout.setf(std::ios::boolalpha);
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;
  
  // Resets to default which is 0/1
  std::cout << std::resetiosflags(std::ios::boolalpha);
  std::cout << "Default (10 == 10): " << (10 == 10) << std::endl;
  std::cout << "Default (10 == 20): " << (10 == 20) << std::endl;

  return 0;
}