#include <iostream>
#include <vector>

/*
! Abstract class
  * Cannot instantiate objects
  * These classes are used as base classes in inheritance hierarchies
  * Often referred to as Abstract Base Classes
  ? Too generic to create objects from
    * Shape, Employee, Account, Player
  ? Serves as parent to Derived classes that may have objects
  ? Contains at least one pure virtual function

! Concrete class
  * Used to instantiate objects from
  * All their member functions are defined
    * Checking Account, Savings Account
    * Faculty, Staff
    * Enemy, Level Boss

! Pure virtual function
  ? Used to make a class abstract
  ? Specified with "=0" in its declaration
  virtual void function() = 0; // pure virtual function
  ? Typically do not provide implementations
  ! Derived classes MUST override the base class
  * If the Derived class does not override then the Derived class is also abstract
  * Used when it doesn't make sense for a base class to have an implementation
    * But concrete classes must implement it
  virtual void draw() = 0; // Shape
  virtual void defend() = 0; // Player
class Shape {
private:
  attributes common to all shapes
public:
  virtual void draw() = 0;
  virtual void rotate() = 0;
  virtual ~Shape();
  ...
};

class Circle : public Shape {
private:
  attributes for a circle
public:
  virtual void draw() override {
    code to draw a circle
  }
  virtual void rotate(float theta) override {
    code to rotate a circle
  }
  virtual ~Circle();
};

! Abstract Base class cannot be instantiated
Shape shape; //! Error
shape *ptr = new Shape; //! Error

* We can use pointers and references to dynamically refer to concrete classes derived from them
Shape *ptr = new Circle;
ptr->draw();
ptr->rotate();
*/

class Shape // Abstract Base class
{
private:
  // attributes common to all shapes
public:
  virtual void draw() = 0;
  virtual void rotate(float theta) = 0;
  virtual ~Shape() {}
};

class Open_Shape : public Shape // Abstract class
{
public:
  ~Open_Shape() {}
};

class Closed_Shape : public Shape // Abstract class
{
public:
  ~Closed_Shape() {}
};

class Line : public Open_Shape // Concrete class
{
public:
  void draw() override { std::cout << "Drawing a line" << std::endl; }
  void rotate(float theta) override { std::cout << "Rotating a line by " << theta << " degrees." << std::endl; }
  ~Line() {}
};

class Circle : public Closed_Shape // Concrete class
{
public:
  void draw() override {std::cout << "Drawing a circle" << std::endl; }
  void rotate(float theta) override { std::cout << "Rotating a circle by " << theta << " degrees." << std::endl; }
  ~Circle() {}
};

class Square : public Closed_Shape // Concrete class
{
public:
  void draw() override {std::cout << "Drawing a square" << std::endl; }
  void rotate(float theta) override { std::cout << "Rotating a square by " << theta << " degrees." << std::endl; }
  ~Square() {}
};

void screen_refresh(const std::vector<Shape*> &shapes) {
  std::cout << "Refreshing" << std::endl;
  for(const auto p : shapes) {
    p->draw();
  }
}

int main()
{
  Line line;
  Circle circle;
  Square square;

  line.draw();
  line.rotate(45);

  circle.draw();
  circle.rotate(45);

  square.draw();
  square.rotate(45);

  Shape* s1 = new Circle;
  Shape* s2 = new Square;
  Shape* s3 = new Line;

  std::vector<Shape*> shapes {s1, s2, s3};
  // for(const auto p : shapes)
  //   p->draw();

  screen_refresh(shapes);

  delete s1;
  delete s2;
  delete s3;

  return 0;
}