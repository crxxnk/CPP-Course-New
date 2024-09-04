#pragma once
#include <string>

class Movie
{
private:
  std::string name;
  std::string rating;
  int watchCount;
public:
  Movie(std::string name, std::string rating, int watchedCount);
  Movie(const Movie &source);
  ~Movie();
  void setName(std::string name) { this->name = name; }
  std::string getName() const { return name; }

  void setRating(std::string rating) { this->rating = rating; }
  std::string getRating() const { return rating; }

  void setWatched(int watchCount) { this->watchCount = watchCount; }
  int getWatched() const { return watchCount; }

  void incrementWatched() { watchCount++; }

  void displayM() const;
};