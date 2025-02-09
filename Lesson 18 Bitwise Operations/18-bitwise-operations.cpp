#include <iostream>
/*
! Bitwise Operations
? Bitwise operations allow us to manipulate individual bits of data.
? This is especially useful when you need to:
* Optimize memory usage by packing multiple boolean flags into a single integer.
* Speed up computations by working with data at the bit level.
* Set, clear, or toggle specific bits to control options or flags.

? Suppose you have settings for a game and you want to store multiple options in a single variable.
? Instead of using multiple variables (which could take more memory), you can use bitwise operations to store the settings compactly.
* For instance:
musicEnabledFlag = 0x01 (binary 0001)
soundEffectsFlag = 0x02 (binary 0010)
fullScreenFlag = 0x04 (binary 0100)

* When we are using powers of two for bit flags,
* the values will follow the pattern of doubling each time
0x01 (binary 0001) → First flag (represents 1 in decimal).
0x02 (binary 0010) → Second flag (represents 2 in decimal).
0x04 (binary 0100) → Third flag (represents 4 in decimal).
0x08 (binary 1000) → Fourth flag (represents 8 in decimal).
0x10 (binary 0001 0000) → Fifth flag (represents 16 in decimal).
0x20 (binary 0010 0000) → Sixth flag (represents 32 in decimal).
0x40 (binary 0100 0000) → Seventh flag (represents 64 in decimal).
0x80 (binary 1000 0000) → Eighth flag (represents 128 in decimal).

! Bitwise operators
Operator  Description                           Example
&	        Bitwise AND	                          a & b
|	        Bitwise OR                            a | b
^	        Bitwise XOR	                          a ^ b
~	        Bitwise NOT(inverts bits)             ~a
<<	      Left Shift(shift bits to the left)	  a << 1
>>	      Right Shift(shift bits to the right)	a >> 1
&=	      Bitwise AND Assignment	              a &= b
|=	      Bitwise OR Assignment                 a |= b
^=	      Bitwise XOR Assignment	              a ^= b

! Bitwise AND (&)
* The bitwise AND operator compares the bits of two numbers and sets the result bit to 1 
* if both corresponding bits are 1, otherwise it sets the result bit to 0.
int a = 5;    // binary: 0101
int b = 3;    // binary: 0011

First bit (leftmost): 0 & 0 = 0
Second bit: 1 & 0 = 0
Third bit: 0 & 1 = 0
Fourth bit (rightmost): 1 & 1 = 1
* That's why
int result = a & b;  // binary: 0001
std::cout << result; // Output: 1

! Bitwise OR (|)
* The bitwise OR operator compares the bits of two numbers and sets the result bit to 1
* if at least one of the corresponding bits is 1.
int a = 5;    // binary: 0101
int b = 3;    // binary: 0011

int result = a | b;  // binary: 0111
std::cout << result; // Output: 7

! Bitwise XOR(^)
* The bitwise XOR operator compares the bits of two numbers and sets the result bit to 1
* if the bits are different (e.g, one is 1 and the other is 0), otherwise it sets the result bit to 0.
int a = 5;    // binary: 0101
int b = 3;    // binary: 0011

int result = a ^ b;  // binary: 0110
std::cout << result; // Output: 6

! Bitwse NOT(~)
* The bitwise NOT operator flips all the bits of a number, changing 1 to 0 and 0 to 1.
* This is also called the one's complement(συμπληρωματικό) of a number.
int a = 5;    // binary: 0101

int result = ~a;  // binary: 1010 (in a signed integer, this represents -6)
! 1010 in binary would usually be 10 in decimal BUT:
* C++ uses two's complement for representing signed integers
? Two's complement is a binary representation method that allows you to represent 
? both positive and negative integers in a consistent way. In this system:
* The most significant bit (MSB, the leftmost bit) indicates the sign of the number:
* If the MSB is 0, the number is positive.
* If the MSB is 1, the number is negative.
std::cout << result; // Output: -6

! Left Shift(<<)
* The left shift operator shifts all the bits of a number to the left by a specified number of positions.
* It essentially multiplies the number by 2 for each position shifted.
int a = 5;    // binary: 0101

int result = a << 1;  // binary: 1010 (which is 10 in decimal)
std::cout << result; // Output: 10

result = a << 2;  // binary: 10100 (which is 20 in decimal)
std::cout << result; // Output: 20

! Right Shift(>>)
* The right shift operator shifts all the bits of a number to the right by a specified number of positions.
* It essentially divides the number by 2 for each position shifted.
int a = 5;    // binary: 0101

int result = a >> 1;  // binary: 0010 (which is 2 in decimal)
std::cout << result;  // Output: 2

! Bitwise AND Assignment (&=)
* This operator performs a bitwise AND between the left operand and the right operand,
* then assigns the result to the left operand.
int a = 5;    // binary: 0101
int b = 3;    // binary: 0011

a &= b;        // a = a & b, which is 0101 & 0011 = 0001
std::cout << a; // Output: 1

! Bitwise OR Assignment
* This operator performs a bitwise OR between the left operand and the right operand,
* then assigns the result to the left operand.
int a = 5;    // binary: 0101
int b = 3;    // binary: 0011

a |= b;        // a = a | b, which is 0101 | 0011 = 0111
std::cout << a; // Output: 7

! Bitwise XOR Assignment(^=)
* This operator performs a bitwise XOR between the left operand and the right operand,
* then assigns the result to the left operand.
int a = 5;    // binary: 0101
int b = 3;    // binary: 0011

a ^= b;        // a = a ^ b, which is 0101 ^ 0011 = 0110
std::cout << a; // Output: 6
*/

constexpr int COLOR_BUFFER_BIT = 0x4000;
constexpr int DEPTH_BUFFER_BIT = 0x0100;
constexpr int STENCIL_BUFFER_BIT = 0x0400;

void clear(int flags) {
  if(flags & COLOR_BUFFER_BIT)
    std::cout << "Clearing Color Buffer Bit" << std::endl;
  if(flags & DEPTH_BUFFER_BIT) 
    std::cout << "Clearing Depth Buffer Bit" << std::endl;
  if(flags & STENCIL_BUFFER_BIT)
    std::cout << "Clearing Stencil Buffer Bit" << std::endl;
}

int main() {
  clear(COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT);

  return 0;
}