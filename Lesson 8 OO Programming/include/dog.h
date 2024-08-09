#include <iostream>
#include <string>
//! These are called include guards. They prevent the compiler to process this file more than once if included in more than one file.
//* Prevents compiler errors
//#ifndef _DOG_H_ // Checks if it is defined. If it is, then the whole file is skipped to the #endif
//#define _DOG_H_ // Defines _DOG_H_
//! We can do all that in just one line by typing:
#pragma once

class Dog {
private:
  int age = 10;
  std::string name;
public:
  int getHumanAge();
  void setName(std::string n);
  void showName();
};
//#endif