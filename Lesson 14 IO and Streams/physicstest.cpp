#include <iostream>
#include <Windows.h>

struct Vec2 {
  float x, y;
};

constexpr float gravity = -9.81;
constexpr float deltaTime = 0.033f;

struct Object {
  Vec2 position;
  Vec2 velocity;
  float mass;
};

void freeFall(Object &obj) {
  if(obj.position.y >= 0) {
    obj.velocity.y += gravity * deltaTime;
    obj.position.y += obj.velocity.y * deltaTime;
  } else {
    obj.position.y = 0;
    obj.velocity.y = 0;
  }
}

void applyForce(Object &obj, float &force) {
  if (obj.mass == 0) {
    std::cerr << "Error: Object mass cannot be zero!" << std::endl;
    return;
  }
  float a = force/obj.mass;
  obj.velocity.y = a*2;
}

int main() {
  int i = 0;
  Object cube;
  cube.position.y = 0;
  cube.mass = 1;
  float force = 10;
  // if(GetAsyncKeyState(0x41) & 0x8000) {
    // }
  bool isForceApplied = false;
  while(cube.position.y >= 0) {
    if(!isForceApplied) {
      applyForce(cube, force);
      isForceApplied = true;
    }
    
    std::cout << cube.position.y << std::endl;
    freeFall(cube);
  }
  // cube.position.y = 100;
  // while(i < 10000) {
  //   if(cube.position.y > 0) {
  //     cube.velocity.y += gravity * deltaTime;
  //     cube.position.y += cube.velocity.y * deltaTime;
  //     std::cout << cube.position.y << std::endl;
  //     i++;
  //   } else
  //       break;
  // }
  return 0;
}