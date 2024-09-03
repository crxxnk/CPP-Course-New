#include <iostream>

class Circle
{
private:
  double radius;
public:
  Circle(double radius): radius(radius){ std::cout << "The radius of the circle is " << radius << std::endl; }
  double* getRadius() { return &radius; }
  double area(double* radius);
  double circumference(double* radius);
};

double Circle::area(double* radius)
{
  if (radius!= nullptr)
    *radius = this->radius;
  return 3.14159265 * (*radius)*(*radius);
}

double Circle::circumference(double* radius)
{
  if (radius!= nullptr)
    *radius = this->radius;
  return 2 * 3.14159265 * (*radius);
}

int main()
{
  Circle circle(1.21325);
  std::cout << "The area of the circle is " << circle.area(circle.getRadius()) << std::endl;
  std::cout << "The circumference of the circle is " << circle.circumference(circle.getRadius()) << std::endl;

  return 0;
}