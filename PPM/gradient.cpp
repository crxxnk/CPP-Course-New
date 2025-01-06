#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

double E(float u)
{
  const double V = 0.0031308;
  const float A = 12.92;
  const float B = 2.4;
  const float C = 0.055;
  if(u <= V)
    return A * u;
  return (1.0f + C)*pow(u, (1/B)) - C;
}

int main()
{
  const int width = 256;
  const int height = 256;

  std::ofstream file("gradient.ppm");
  file << "P3\n" << width << " " << height << " " << "255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      float factor = x / float(width);
      float r = 0.0f, g = 0.0f, b = 0.0f;

      r = x / float(width);
      g = 1.0f - (x / float(width));

      double renc = E(r);
      double genc = E(g);
      float benc = pow(b, (1/2.2));

      int ir = static_cast<int>(renc * 255.0f);
      int ig = static_cast<int>(genc * 255.0f);
      int ib = static_cast<int>(benc * 255.0f);
      
      file << ir << " " << ig << " " << ib << " ";
    }
  }
  file.close();

  return 0;
}