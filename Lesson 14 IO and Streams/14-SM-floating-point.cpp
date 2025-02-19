/*
! Formatting floating point types
? Default when displaying floating point values is:
  * setprecision - number of digits displayed (6)
  * fixed - not fixed to a specific number of digits after the decimal point
  * noshowpoint - trailing zeroes are not displayed
  * nouppercase - when displaying in scientific notation
  * noshowpos - no '+' is displayed for positive numbers
? These manipulators affect all further output to the stream

double num = 1234.5678;
std::cout << num < std::endl;
Will display
1234.57 // Notice precision is 6 and rounding

double num = 123456789.987654321;
std::cout << num << std::endl;
Will display
1.23457e+008 // Notice precision is 6

double num = 123456789.987654321;
std::cout << std::setprecision(9);
std::cout << num << std::endl;
Will display
123456790 // Note that rounding occurs

double num = 123456789.987654321;
std::cout << std::fixed;
std::cout << num << std::endl;
Will display precision 6 from the decimal
123456789.987654

double num = 123456789.987654321;
std::cout << std::setprecision(3) << std::fixed;
std::cout << num << std::endl;
Will display precision 3 from the decimal
123456789.988
*/