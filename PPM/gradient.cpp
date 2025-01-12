#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

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

int main()
{
  const char* filePath = "C:/Users/PC/Downloads/gradient.ppm";
  const int width = 500;
  const int height = 70;
  const float glowRadius = 150.0f;

  std::ofstream file(filePath);
  file << "P3\n" << width << " " << height << " " << "255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      float fWidth = static_cast<float>(width);
      float r = 1.0f, g = 0.5f, b = 0.0f;

      r = lerp(1.0f, 0.0f, x / fWidth);
      g = lerp(0.5f, 0.0f, x / fWidth);
      b = lerp(0.0f, 1.0f, x / fWidth);

      // r = applyGlow(r, x, y, width, height, glowRadius);
      // g = applyGlow(g, x, y, width, height, glowRadius);
      // b = applyGlow(b, x, y, width, height, glowRadius);

      // r = lerp(0.0f, 1.0f, x / fWidth);
      // g = lerp(1.0f, 0.0f, x / fWidth);

      // r = 1.0f - (x / fWidth);
      // g = 0.5f - (x / fWidth);
      // b = x / fWidth;

      double renc = E(r);
      double genc = E(g);
      double benc = E(b);

      int ir = static_cast<int>(renc * 255.0f);
      int ig = static_cast<int>(genc * 255.0f);
      int ib = static_cast<int>(benc * 255.0f);
      
      file << ir << " " << ig << " " << ib << " ";
    }
  }
  file.close();

  return 0;
}