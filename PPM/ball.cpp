#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
  const int width = 256;
  const int height = 256;

  const int cx = 128;
  const int cy = 128;
  const int rad = 50;

  std::ofstream file("ball.ppm");

  file << "P3\n" << width << " " << height << " " << "\n255\n";

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      int r = x;
      int g = y;
      int b = 255 - y;

      int dx = x - cx;
      int dy = y - cy;

      if(dx * dx + dy * dy <= rad * rad) {
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