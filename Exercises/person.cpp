#include <iostream>

class Person
{
private:
  std::string name;
  int age;
  std::string country;
public:
  Person(std::string name, int age, std::string country): name(name), age(age), country(country) { std::cout << "A person was just born" << std::endl; }
  ~Person() { std::cout << "A person just died" << std::endl; }
  std::string getName() { return name; }
  int getAge() { return age; }
  std::string getCountry() { return country; }
};

int main()
{
  Person Alex("Alex", 15, "Greece");
  std::cout << "Name: " << Alex.getName() << ", Age: " << Alex.getAge() << ", Country: " << Alex.getCountry() << std::endl;

  return 0;
}