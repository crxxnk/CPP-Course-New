#include <iostream>
#include <iomanip>
/*
! Formatting integer types
? Default when displaying integer values is:
  * dec(base 10)
  * noshowbase - prefix used to show hexadecimal or octal
  * nouppercase - when displaying a prefix and hex values it will be lower case
  * noshowpos - no '+' is displayed for positive numbers
? These manipulators affect all further output to the stream

int num = 255;
std::cout << std::dec << num << std::endl;
std::cout << std::hex << num << std::endl;
std::cout << std::oct << num << std::endl;
Will display
255
ff
377

std::cout << std::showbase;
std::cout << std::dec << num << std::endl;
std::cout << std::hex << num << std::endl;
std::cout << std::oct << num << std::endl;
Will display
255
0xff // note the 0x prefix for hexadecimal
0377 // note the 0 prefix for octal

std::cout << std::showbase << std::uppercase;
std::cout << std::hex << num << std::endl;
Will display
0XFF // note capitalized XFF

int num1 = 255;
int num2 = -255;

std::cout << num1 << std::endl;
std::cout << num2 << std::endl;
std::cout << std::showpos;
std::cout << num1 << std::endl; // +255
std::cout << num2 << std::endl; // -255

? Setting/resetting integer types
* Set using setf
std::cout.setf(std::ios::showbase);
std::cout.setf(std::ios::uppercase);
std::cout.setf(std::ios::showpos);

* Reset to defaults
std::cout << std::resetiosflags(std::ios::basefield);
std::cout << std::resetiosflags(std::ios::showbase);
std::cout << std::resetiosflags(std::ios::showpos);
std::cout << std::resetiosflags(std::ios::uppercase);
*/

int main() {
  int num;
  std::cout << "Enter an integer: ";
  std::cin >> num;

  std::cout << "Decimal: " << num << std::endl;
  std::cout << "Hexadecimal: " << std::hex << num << std::endl;
  std::cout << "Octal: " << std::oct << num << std::endl;

  return 0;
}