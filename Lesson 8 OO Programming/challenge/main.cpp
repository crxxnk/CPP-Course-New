#include <iostream>
#include "Movies.h"
#include "Movies.cpp"
#include "Movie.cpp"

void incrementWatched(Movies &movies, std::string name);
void addMovie(Movies &movies, std::string name, std::string rating, int watchedCount);

int main()
{
  Movies myMovies;
  myMovies.display();

  addMovie(myMovies, "Big", "PG-13", 2);
  addMovie(myMovies, "Star Wars", "PG", 5);
  addMovie(myMovies, "Cinderella", "PG", 7);

  myMovies.display();

  addMovie(myMovies, "Cinderella", "PG", 7);
  addMovie(myMovies, "Ice Age", "PG", 12);

  myMovies.display();

  incrementWatched(myMovies, "Big");
  incrementWatched(myMovies, "Ice Age");

  myMovies.display();

  incrementWatched(myMovies, "XXX");

  return 0;
}

void incrementWatched(Movies &movies, std::string name) {
  if(movies.incrementWatched(name))
    std::cout << name << " watch incremented" << std::endl;
  else
    std::cout << name << " not found" << std::endl;
}

void addMovie(Movies &movies, std::string name, std::string rating, int watchedCount) {
  if(movies.addMovie(name, rating, watchedCount))
    std::cout << name << " added" << std::endl;
  else
    std::cout << name << " already exists" << std::endl;
}