#include <iostream>
#include <fstream>

int main()
{
  const int width = 256;
  const int height = 256;

  std::ofstream file("blue.ppm");
  file << "P3\n" << width << " " << height << " " << "255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      int r = 0;
      int g = 0;
      int b = 255;
      file << r << " " << g << " " << b << " ";
    }
  }
  file.close();

  return 0;
}