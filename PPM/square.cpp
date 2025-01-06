#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
  const int width = 256;
  const int height = 256;

  const int sx = 100;
  const int sy = 100;
  const int side = 50;

  std::ofstream file("square.ppm");
  
  file << "P3\n" << width << " " << height << " " << "\n255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      int r = x;
      int g = y;
      int b = 255 - y;

      if(sx <= x && x < sx + side && sy <= y && y < sy + side) {
        r = 255;
        g = 0;
        b = 0;
      }

      file << r << " " << g << " " << b << " ";
    }
    file << "\n";
  }
  file.close();

  return 0;
}