#include <memory>
#include <iostream>

/*
! The weak_ptr
* Provides a non-owning "weak" reference
? weak_ptr<T>
  * Points to an object of type T on the heap
  * Does not participate in owning relationship
  * Always created from a shared_ptr
  * Does NOT increment or decrement reference use count
  * Used to prevent strong reference cycles which could prevent objects from being deleted

? weak_ptr - circular or cyclic reference
* A refers to B
* B refers to A
! Shared strong ownership prevents heap deallocation

? Solution - make one of the pointers non-owning or 'weak'
* Now heap storage is deallocated properly
*/

class B;

class A
{
  std::shared_ptr<B> b_ptr;
public:
  void set_B(std::shared_ptr<B> &b) { b_ptr = b; }
  A() { std::cout << "A Constructor" << std::endl; }
  ~A() { std::cout << "A Destructor" << std::endl; }
};

class B
{
  std::weak_ptr<A> a_ptr;
public:
  void set_A(std::shared_ptr<A> &a) { a_ptr = a; }
  B() { std::cout << "B Constructor" << std::endl; }
  ~B() { std::cout << "B Destructor" << std::endl; }
};

int main()
{
  //! A and B will never get destroyed because a points to b and b points to a, to fix this make the A pointer in B class weak or the other way
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->set_B(b);
  b->set_A(a);

  return 0;
}