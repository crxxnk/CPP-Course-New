#include <iostream>
#include <ostream>

struct Vector3 {
  float x, y, z;

  friend std::ostream &operator<<(std::ostream &os, Vector3 &rhs) {
    os << rhs.x << " " << rhs.y << " " << rhs.z;
    return os;
  }

  Vector3 &operator+=(Vector3 &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

};

int main()
{
  Vector3 vec {10,20,30};
  Vector3 vec2{40,50,60};
  vec+=vec2;

  std::cout << vec << std::endl;

  return 0;
}