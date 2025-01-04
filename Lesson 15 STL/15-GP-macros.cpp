/*
! Generic Programming with macros
? Generic programming
"Writing code that works with a variety of types as arguments, as long as those argument
types meet specific syntactic and semantic requirements", Bjarne Stroustrup(Creator of C++)
? Macros ***beware***
? Function templates
? Class templates

! Macros(#define)
? C++ preprocessor directives
? No type information
? Simple substitution

#define MAX_SIZE 100
#define PI 3.14159

if(num > MAX_SIZE)
  std::cout << "Too big";

double area = PI * r * r;

#define MAX_SIZE 100 //! removed
#define PI 3.14159 //! removed

if(num > 100) //! replaced
  std::cout << "Too big";

double area = 3.14159 * r * r; //! replaced

? Suppose we need a function to determine the max of 2 integers
int max(int a, int b) {
  return (a > b) ? a : b;
}

int x = 100;
int y = 200;
std::cout << max(x, y) // displays 200

? Now suppose we need to determine the max of 2 doubles, and 2 chars
int max(int a, int b) {
  return (a > b) ? a : b;
}

double max(double a, double b) {
  return (a > b) ? a : b;
}

char max(char a, char b) {
  return (a > b) ? a : b;
}

* We can write a generic macro with arguments instead of 3 functions
#define MAX(a, b) ((a> b) ? a : b)

std::cout << MAX(10, 20) << std::endl; // 20
std::cout << MAX(2.4, 3.5) << std::endl; // 3.5
std::cout << MAX('A', 'C') << std::endl; // C

! We have to be careful with macros
#define SQUARE(a) a*a

result = SQUARE(5); // Expect 25
result = 5*5; // Get 25

result = 100/SQUARE(5); // Expect 4
result = 100/5*5 // Get 100!

* To fix it
#define SQUARE(a) ((a)*(a)) // note the parenthesis
result = SQUARE(5); // Expect 25
result = 5*5; // Get 25

result = 100/SQUARE(5); // Expect 4
result = 100/((5)*(5)) // Get 4!
*/