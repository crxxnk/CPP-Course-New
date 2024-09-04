#include <iostream>
#include "Movies.h"

Movies::Movies(){}
Movies::~Movies(){}

bool Movies::addMovie(std::string name, std::string rating, int watchedCount){
  Movie m(name, rating, watchedCount);
  for(auto& movie : movies){
    if(movie.getName() == name && movie.getRating() == rating && movie.getWatched() == watchedCount) {
      return false;
    }
  }
  movies.push_back(m);
  return true;
}

bool Movies::incrementWatched(std::string name){
  for(auto& movie : movies){
    if(movie.getName() == name) {
      movie.incrementWatched();
      return true;
    }
  }
  return false;
}

void Movies::display() const {
  if(movies.empty())
    std::cout << "Sorry, no movies to display." << std::endl;
  for(auto movie : movies){
    movie.displayM();
  }
}