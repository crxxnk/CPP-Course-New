/*
! Modules
? Modules, introduced in C++20, provide a modern, efficient alternative to the traditional #include preprocessor directive for code organization and compilation.
? They help eliminate common problems associated with header files and improve build times.

* Module Declaration(export module)
Declares a module and specifies its interface.
* Exported Functions / Classes(export)
Defines what parts of the module are accessible outside.
* Importing Modules(import)
Allows other translation units to access module content.
* Example :
	math_module.cppm / ixx
	export module math_module;
*/

export int add(int a, int b) {
	return a + b;
}

export int subtract(int a, int b) {
	return a - b;
}

export module math_module;

import <iostream>;

/* kinda just writing
void helloImpl(const char* name);

export void hello(const char* name) {
	helloImpl(name);
}

void helloImpl(const char* name) {
	std::cout << "Hello " << name << std::endl;
}
*/

export void hello(const char* name) {
	std::cout << "Hello " << name << std::endl;
}

export namespace math {
	void add(int a, int b) {
		std::cout << a + b << std::endl;
	}

	void subtract(int a, int b) {
		std::cout << a - b << std::endl;
	}
}

export struct Entity {
	int id;
	int health;
};