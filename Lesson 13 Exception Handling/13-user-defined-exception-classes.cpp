#include <iostream>

/*
! User-defined exceptions
? We can create exception classes and throw instances of those classes
? Best practice:
  * throw an object not a primitive type
  * throw an object by value
  * catch an object by reference(or const reference)
class DivideByZeroException {
};

class NegativeValueException {
};

* Throwing user-defined exception classes
double calculate_mpg(int miles, int gallons) {
  if(gallons == 0)
    throw DivideByZeroException();
  if(miles < 0 || gallons < 0)
    throw NegativeValueException();
  return static_cast<double>(miles) / gallons;
}

try {
  miles_per_gallon = calculate_mpg(miles, gallons);
  std::cout << miles_per_gallon << std::endl;
}
catch(const DivideByZeroException &e) {
  std::cerr << "You can't divide by zero" << std::endl;
}
catch(const NegativeValueException &e) {
  std::cerr << "Negative values aren't allowed" << std::endl;
}
*/

class DivideByZeroException {
};

class NegativeValueException {
};

double calculate_mpg(int miles, int gallons) {
  if(gallons == 0)
    throw DivideByZeroException();
  if(miles < 0 || gallons < 0)
    throw NegativeValueException();
  return static_cast<double>(miles) / gallons;
}

int main()
{
  int miles;
  int gallons;
  double miles_per_gallon;

  std::cout << "Enter the miles driven: ";
  std::cin >> miles;
  std::cout << "Enter the gallons used: ";
  std::cin >> gallons;

  try {
    miles_per_gallon = calculate_mpg(miles, gallons);
    std::cout << miles_per_gallon << " miles per gallon" << std::endl;
  }
  catch(const DivideByZeroException &e) {
    std::cerr << "You can't divide by zero" << std::endl;
  }
  catch(const NegativeValueException &e) {
    std::cerr << "Negative values aren't allowed" << std::endl;
  }

  return 0;
}