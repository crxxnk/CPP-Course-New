#pragma once
#include <ostream>

class I_Printable
{
  friend std::ostream &operator<<(std::ostream os, const I_Printable &obj);
public:
  virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}