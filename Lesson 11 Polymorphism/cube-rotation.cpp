#include <iostream>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>

float A, B, C;

float x, y, z;
float ooz;
int xp, yp;

float cubeWidth = 10;
int width = 80;
int height = 22;
float zBuffer[80 * 22];
char buffer[80 * 22];
int backgroundASCIICode = ' ';
int distanceFromCam = 60;
float K1 = 40;
int idx;

float incSpeed = 1.2;

float calculateX(int i, int j, int k) {
  return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + k * sin(A) * sin(C) + j * cos(A) * sin(C) + i * cos(B) * cos(C);
}

float calculateY(int i , int j, int k) {
  return k * sin(A) * cos(C) + j * cos(A) * cos(C) - j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) - i * cos(B) * sin(C);
}

float calculateZ(int i, int j, int k) {
  return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
  x = calculateX(cubeX, cubeY, cubeZ);
  y = calculateY(cubeX, cubeY, cubeZ);
  z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

  ooz = 1 / z;

  xp = (int)(width / 2 + K1 * ooz * x * 2);
  yp = (int)(height / 2 + K1 * ooz * y);

  idx = xp + yp * width;
  if (idx >= 0 && idx < width * height) {
    if (ooz > zBuffer[idx]) {
      zBuffer[idx] = ooz;
      buffer[idx] = ch;
    }
  }
}

int main() {
  std::cout << "\x1b[2J";
  while (true) {
    memset(buffer, backgroundASCIICode, width * height);
    memset(zBuffer, 0, width * height * 4);

    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incSpeed) {
        calculateForSurface(cubeX, cubeY, -cubeWidth, '.'); // Πίσω
        calculateForSurface(cubeWidth, cubeY, cubeX, '$'); // Δεξιά
        calculateForSurface(-cubeWidth, cubeY, -cubeX, '~'); // Αριστερά
        calculateForSurface(-cubeX, cubeY, cubeWidth, '#'); // Μπροστά
        calculateForSurface(cubeX, -cubeWidth, -cubeY, ';'); // Κάτω
        calculateForSurface(cubeX, cubeWidth, cubeY, '+'); // Πάνω
      }
    }
    cubeWidth = 10;

    std::cout << "\x1b[H";
    for (int i = 0; i < width * height; i++) {
      putchar(i % width ? buffer[i] : 10);
    }

    A += 0.05;
    B += 0.05;
    C += 0.03;

    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }

  return 0;
}
