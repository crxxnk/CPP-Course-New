#include <iostream>

struct Vec2 {
  float x,y;
};

struct Object {
  Vec2 position;
  Vec2 velocity {0, 1.2};
};

constexpr float deltaTime = 0.016f;

void applyVelocity(Object &obj, Vec2 velocity) {
  obj.position.y += velocity.y * deltaTime;
}

int main() {
  Object ball;
  ball.position.y = 100;
  while(ball.position.y > 0) {
    applyVelocity(ball, Vec2{0, -1});
    std::cout << ball.position.y << std::endl;
  }
}