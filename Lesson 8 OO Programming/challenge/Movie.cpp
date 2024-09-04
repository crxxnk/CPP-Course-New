#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watched):name(name),rating(rating),watchCount(watched){}

Movie::Movie(const Movie &source):Movie(source.name, source.rating, source.watchCount){}

Movie::~Movie(){}

void Movie::displayM() const {
  std::cout << name << ", " << rating << ", " << watchCount << std::endl;
}