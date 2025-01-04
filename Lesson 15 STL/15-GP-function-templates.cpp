#include <iostream>

/*
! Generic Programming with function templates
? What is a C++ Template?
* Blueprint
* Function and class templates
* Allow plugging-in any data type
* Coimpiler generates the appropriate function/class from the blueprint
* Generic programming / meta-programming

* Let's revisit the max function from the previous lecture
int max(int a, int b) {
  return (a > b) ? a : b;
}

int x = 100;
int y = 200;
std::cout << max(x, y); // displays 200

? Now suppose we need to determine the max of 2 doubles, and 2 chars
int max(int a, int b) {
  return (a > b) ? a : b;
}

double max(double a, double b) {
  return (a > b) ? a : b;
}

char max(char a, char b) {
  return (a > b) ? a : b;
}

* We can replace the type we want to generalize with a name, say T
* But now this won't compile

T max(T a, T b) {
  return (a > b) ? a : b;
}

* We need to tell the compiler this is a template function
* We also need to tell it that T is the template parameter
* This will compile but won't generate any code

template <typename T>
T max(T a, T b) {
  return (a > b) ? a : b;
}

* We may also use class instead of typename

template <class T>
T max(T a, T b) {
  return (a > b) ? a : b;
}

* Now the compiler can generate the appropriate function from the template
* Note, this happens at compile-time.

int a = 10;
int b = 20;
std::cout << max<int>(a,b);

* Many times the compiler can deduce the type and the template parameter is not needed
* Depending on the type of a and b, the compiler will figure it out

std::cout << max<double>(c,d);
std::cout << max(c,d);

* And we can use almost any type we need

char a = 'A';
char b = 'B';
std::cout << max(a, b) << std::endl;

! Notice the type MUST support the > operator either natively or as an overloaded operator(operator>)

template <typename T>
T max(T a, T b) {
  return (a > b) ? a : b;
}

! The following will not compile unless Player overloads operator>

Player p1("Hero", 100, 20);
Player p1("Enemy", 99, 3);
std::cout << max<Player>(p1, p2);

* We can also have multiple template parameters
* And their types can be different

template <typename T1, typename T2>
void func(T1 a, T2 b) {
  std::cout << a << " " << b;
}

* When we use the function we provide the template parameters
* Often the compiler can deduce them

func<int, double>(10, 20.2);
func('A', 12.4);
*/

template <typename T>
T min(T a, T b) {
  return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
  std::cout << a << " " << b << std::endl;
}

struct Person
{
  friend std::ostream &operator<<(std::ostream& os, const Person &obj); // don't need the friend because every field is public
  std::string name;
  int age;
  bool operator<(const Person &rhs) const { return this->age < rhs.age; }
};

std::ostream &operator<<(std::ostream& os, const Person &obj)
{
  os << obj.name << " " << obj.age;
  return os;
}

template<typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main()
{
  int x = 100;
  int y = 200;
  std::cout << x << " " << y << std::endl;
  swap(x, y);
  std::cout << x << " " << y << std::endl;

  Person p1{"Alex", 16};
  Person p2{"Rita", 12};

  func(p1, p2);
  swap(p1, p2);
  func(p1, p2);

  Person p3 = min(p1, p2);
  std::cout << p3.name << " is younger" <<std::endl;

  std::cout << min<int>(2,3) << std::endl;
  std::cout << min(2,3) << std::endl;
  std::cout << min('A','B') << std::endl;
  std::cout << min(12.5,9.2) << std::endl;
  std::cout << min<int>(5+2*2,7+40) << std::endl;

  func<int, int>(10, 20);
  func(10, 20);
  func<char, double>('A', 12.4);
  func('A', 12.4);
  func(1000, "Testing");
  func(2000, std::string("Alex"));
  Person* p4 = new Person{"Frank", 45};
  func<Person, Person>(p1, *p4);
  delete p4;

  return 0;
}