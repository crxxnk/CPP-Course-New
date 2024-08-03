#include <iostream>

using namespace std;

class Students {
  public:
    int age;
    string name;
    double gpa;

  Students(int age, string name, double gpa): age(age), name(name), gpa(gpa){}
};

int main() {
  Students student1(15, "Alex", 4.7);
  cout << student1.name << endl;

  return 0;
}
