#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <map>
#include <array>
#include <cstdint>

float lerp(float v0, float v1, float t) {
  return v0 + t * (v1 - v0);
}

double E(float u) {
  const double V = 0.0031308;
  const float A = 12.92;
  const float B = 2.4;
  const float C = 0.055;
  if(u <= V)
    return A * u;
  return (1.0f + C)*pow(u, (1/B)) - C;
}

float toLinear(float color) {
  if (color <= 0.04045)
    return color / 12.92;
  return pow(((color + 0.055) / 1.055), 2.4);
}

float applyGlow(float baseColor, float x, float y, float width, float height, float glowRadius) {
  float cx = width / 2.0f;
  float cy = height / 2.0f;
  float distance = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
  
  float glowFactor = exp(-distance / glowRadius);
  
  return baseColor * (1.0f + glowFactor);
}

struct Color {
  int r,g,b;
};

enum ColorSelector {
  RED,
  GREEN,
  BLUE,
  WHITE,
  BLACK
};

std::vector<ColorSelector> selectColor() {
  std::string dickColor;
  std::string backGroundColor;
  do {
    std::cout << "What color would you like the dick to be? [RED, GREEN, BLUE, BLACK, WHITE] ";
    std::cin >> dickColor;
    std::cout << "What color would you like the background to be? [RED, GREEN, BLUE, BLACK, WHITE] ";
    std::cin >> backGroundColor;
  } while(dickColor == backGroundColor);
  if(dickColor == "RED")
    return {RED, RED};
}

int main()
{
  const char* filePath = "colors.ppm";
  uint16_t pixelSize = 64;
  uint16_t width = 3 * pixelSize;
  uint16_t height = 3 * pixelSize;
  std::array<std::array<int, 3>, 3> map {{
    {0,1,0},
    {0,1,0},
    {1,1,1}
  }};

  std::map<int, Color> colorMap {
    {0, {0, 0, 0}},
    {1, {255, 0, 0}},
    {2, {0, 255, 0}},
    {3, {0, 0, 255}},
    {4, {255, 255, 255}}
  };

  std::ofstream file(filePath);
  file << "P3\n" << width << " " << height << " " << "255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      int _x = x / pixelSize;
      int _y = y / pixelSize;
      int colorIndex = map[_y][_x];
      Color color = colorMap[colorIndex];
      
      file << color.r << " " << color.g << " " << color.b << " ";
    }
  }
  file.close();

  return 0;
}