#include <iostream>
#include <concepts>

/*
Concepts are a way to specify requirements or constraints on template parameters.
They allow you to define conditions that a type must satisfy to be used with a template.
For example, you can specify that a template parameter must be an integral type, or that it must support certain operations.

* Example
template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T add(T a, T b) {
	return a + b;
}

add(1,2); // works
add(1.3,9) // doesnt work

! Standard Library Concepts
*Concept			Description
std::same_as		Types are exactly the same
std::derived_from	One type is derived from another
std::convertible_to	Types can be converted
std::integral		Type is an integral type
std::floating_point	Type is a floating-point type
std::ranges::range	Type models a range (e.g., vector)
*/

//* Example
template<typename T>
// Works with both integral and floating point but they must be the same type
concept Arithmetic = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Arithmetic T>
T add(T a, T b) {
	return a + b;
}

//* Example of std::same_as (self explenatory, checks if 2 arguments are of the same type)
template <typename T, typename U>
std::strong_ordering compare(T a, U b) {
	// static_assert allows us to check conditions during compilation instead of runtime.
	// If the condition fails, the compilation stops with an error message.
	static_assert(std::same_as<T, U>, "Types must be the same!");
	return a <=> b; // Returns a negative value if less, zero if equal and positive if greater
}

template <typename T>
// Here, the Addable concept ensures that the Calculator class only accepts types that support the + operator.
concept Addable = requires(int a, int b) { a + b; };

template <Addable T>
struct Calculator {
	T add(T a, T b) { return a + b; }
};

struct player {
	int power;
};

//* Different example with convertible_to
//* Checks if the argument is convertible to the specified type
void func(std::convertible_to<int> auto cock) { std::cout << cock << std::endl; }

int main()
{
	float e = 1;
	func(e);

	std::cout << add(10.7, 1.2) << std::endl;
	//add(2, 1.3); // Error

	if (compare(5, 3) == std::strong_ordering::greater) // Works
		std::cout << "Greater" << std::endl;
	//compare(5, 3.0);  // Error, types are not the same

	Calculator<int> calc;
	std::cout << calc.add(10, 3) << std::endl;

	return 0;
}