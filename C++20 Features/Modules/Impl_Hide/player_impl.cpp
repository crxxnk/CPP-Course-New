// tells the compiler that the code following is part of the module player
module player; // player implementation
import <iostream>;

typedef unsigned int uint_t;

struct Player {
	std::string name;
	uint_t id;
	uint_t age;
	Player& operator+=(const Player &rhs) {
		this->age += rhs.age;
		return *this; // return the lhs(modified object)
	}
};