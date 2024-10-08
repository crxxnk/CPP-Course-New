#include <iostream>
#include <cstring>

/*
! Operator Overloading
? What is operator overloading?

* Using traditional operators such as +, =, *, etc. with user-defined types
* Allows user defined types to behave similar to built-in types
* Can make code more readable and writable
* Not done automatically (except for the assignment operator)
* They must be explicitly defined

? Suppose we have a Number class that models any number
* Using functions:
  Number result = multiply(add(a,b), divide(c,d));
* Using member methods:
  Number result = (a.add(b)).multiply(c.divide(d));
* Using overloaded operators:
  Number result = (a+b) * (c/d);

? What operators can be overloaded?
* The majority of C++'s operators can be overloaded
* The following operators cannot be overloaded:
[::, :?, .*, ., sizeof]

! Basic Rules
* Presedence and Associativity cannot be changed
* 'arity' cannot be changed (i.e. can't make the division operator unary)
* Can't overload operators for primitive type (e.g. int, double, etc.)
* Can't create new operators
* [], (), ->, and the assignment operator(=) must be declared as member methods
* Other operators can be declared as member methods or global functions
*/

class MyString
{
private:
  char* str;
public:
  MyString();
  MyString(const char* s);
  MyString(const MyString &source);
  ~MyString();
  void display() const;
  int getLength() const;
  const char* getStr() const;
};

MyString::MyString(): str(nullptr) {
  str = new char[1]; // Allocates memory for one character
  *str = '\0'; // Assigns the null terminator to the character so it's just an empty string
}

MyString::MyString(const char* s): str(nullptr) {
  if (s == nullptr) {
    str = new char[1];
    *str = '\0';
  } else {
    str = new char[std::strlen(s)+1]; // Checks the length of the string and allocates it + 1 for the null terminator
    std::strcpy(str, s); // Copies s to str
  }
}

//!                              source = a
MyString::MyString(const MyString &source): str(nullptr) { // MyString a {"Hello"}; MyString b {a};
  str = new char[std::strlen(source.str)+1];
  std::strcpy(str, source.str); // Copies a to str
}

MyString::~MyString(){
  delete[] str;
}

void MyString::display() const {
  std::cout << str << ": " << getLength() << std::endl;
}

int MyString::getLength() const {
  return std::strlen(str);
}

const char* MyString::getStr() const {
  return str;
}

int main()
{
  std::string name = "Alex";
  std::string space = " ";
  std::string lastName = "Karakasidis";
  std::string fullName = name + space + lastName;

  int b = 10;
  int c = 20;
  int a = b + c;
  a < b;
  std::cout << a << std::endl;
  std::cout << fullName << std::endl;

  //-----------------------------------------------

  MyString empty;
  MyString alex("Alex");
  MyString guy{alex}; // Copy constructor is called

  empty.display();
  alex.display();
  guy.display();

  return 0;
}