#pragma once
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
private:
  std::vector<Movie> movies;
public:
  Movies();
  ~Movies();
  bool incrementWatched(std::string name);
  void display() const;
  bool addMovie(std::string, std::string rating, int wacthedCount);
};