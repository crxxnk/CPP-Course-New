#include <iostream>

using namespace std;

class Students {
  public:
    int age;
    string name;
    double gpa;

  Students(int age, string name, double gpa){
    this->age = age;
    this->name = name;
    this->gpa = gpa;
  }
};

int main() {
  Students student1(15, "Alex", 4.7);
  cout << student1.gpa << endl;

  return 0;
}
