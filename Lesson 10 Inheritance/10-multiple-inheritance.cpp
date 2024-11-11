/*
! Multiple Inheritance
? A derived class inherits from two or more Base classes at the same time
? The Base classes may belong to unrelated class hierarchies
? A Department Chair
  * Is-A Faculty and
  * Is-A Administrator
class Department_Chair : public Faculty, public Administrator
{
...
};
* Beyond the scope of this course
* Some compelling use-cases
* Easily misused
* Can be very complex
*/