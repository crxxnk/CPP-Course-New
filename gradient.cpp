#include <iostream>
#include <fstream>

int main()
{
  const int width = 256;
  const int height = 256;

  std::ofstream file("gradient.ppm");
  file << "P3\n" << width << " " << height << " " << "255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      int r = x;
      int g = y;
      int b = 255 - y;
      file << r << " " << g << " " << b << " ";
    }
  }
  file.close();

  return 0;
}