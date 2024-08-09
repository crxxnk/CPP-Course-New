#include "include/dog.h" // include the dog.h header file so we can access the classes

int Dog::getHumanAge() {
  return age * 7;
}

void Dog::setName(std::string n) {
  name = n;
}

void Dog::showName() {
  std::cout << name << std::endl;
}

int main() {
  Dog dog;
  dog.setName("Rush");
  std::cout << dog.getHumanAge() << std::endl;
  Dog *puppy = new Dog;
  puppy->setName("Ruby");
  puppy->showName();
  delete puppy;

  return 0;
}