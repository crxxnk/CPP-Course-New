#include <iostream>
#include <fstream>

int main()
{
  const int width = 256;
  const int height = 256;
  const int cubeSize = 32;
  std::ofstream file("checkboard.ppm");
  file << "P3\n" << width << " " << height << "\n255\n";
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      bool isBlue = ((x/cubeSize) % 2 == (y/cubeSize) % 2);
      int r = isBlue ? 0 : 255;
      int g = isBlue ? 0 : 255;
      int b = 255;
      file << r << " " << g << " " << b << " ";
    }
  }
  file.close();

  return 0;
}