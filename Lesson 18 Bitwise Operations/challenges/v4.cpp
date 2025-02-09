#include <iostream>

typedef int hex;
int permissions = 0;
constexpr int READ = 0x01;
constexpr int WRITE = 0x02;
constexpr int EXECUTE = 0x04;
constexpr int DELETE = 0x08;

bool has_permission(int permissions, hex flag) {
  return permissions & flag;
}

void set_permission(int &permissions, hex flag) {
  permissions |= flag;
}

void remove_permission(int &permissions, hex flag) {
  permissions &= ~flag;
}

int main() {
  set_permission(permissions, 0x01);
  set_permission(permissions, 0x02);

  if(has_permission(permissions, 0x01))
    std::cout << "User has READ permission." << std::endl;
  
  if(!has_permission(permissions, 0x04))
    std::cout << "User does NOT have EXECUTE permission." << std::endl;

  set_permission(permissions, 0x04);

  if(has_permission(permissions, 0x02))
    std::cout << "User has WRITE permission." << std::endl;
  
  remove_permission(permissions, 0x02);
  if (!has_permission(permissions, 0x02))
    std::cout << "User does NOT have WRITE permission anymore." << std::endl;

  return 0;
}