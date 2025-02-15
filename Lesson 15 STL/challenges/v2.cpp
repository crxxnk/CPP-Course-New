#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

struct Songs {
  friend std::ostream &operator<<(std::ostream &os, const Songs &song);
  std::string song_name;
  std::string artist_name;
  unsigned int rating;
  Songs(std::string song_name, std::string artist_name, unsigned int rating) : 
  song_name(song_name), artist_name(artist_name), rating(rating) {}
};

std::ostream &operator<<(std::ostream &os, const Songs &song) {
  os << std::setw(20) << std::left << song.song_name << std::setw(30) << std::left << song.artist_name << std::setw(2) << std::left << song.rating;
  return os;
}

void display(std::list<Songs> &songs, std::list<Songs>::iterator it) {
  for(const auto &s : songs)
    std::cout << s << std::endl;
  std::cout << "Current song: " << std::endl;
  std::cout << *it << std::endl;
}

int main() {
  std::list<Songs> songs;
  songs.emplace_back("Brad Pitt", "Playboi Carti", 5);
  songs.emplace_back("For you", "Ken Carson", 4);
  songs.emplace_back("Surf", "Young Thug", 2);
  songs.emplace_back("Shake it off", "Taylor Swift", 1);
  songs.emplace_back("Made Sum Plans", "Osamason", 3);

  char selection;
  auto it = songs.begin();

  do {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
    std::cin >> selection;

    if(selection == 'f' || selection == 'F') {
      std::cout << "Playing first song" << std::endl;
      std::cout << "Playing:" << std::endl;
      std::cout << *songs.begin() << std::endl;
    } else if(selection == 'n' || selection == 'N') {
      if(it != --songs.end()) 
        it++;
      else
        it = songs.begin();
      std::cout << "Playing next song" << std::endl;
      std::cout << "Playing:" << std::endl;
      std::cout << *it << std::endl;
    } else if(selection == 'p' || selection == 'P') {
      if(it != songs.begin()) 
        it--;
      else
        it = --songs.end();
      std::cout << "Playing previous song" << std::endl;
      std::cout << "Playing:" << std::endl;
      std::cout << *it << std::endl;
    } else if(selection == 'a' || selection == 'A') {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::string s_name;
      std::string art_name;
      unsigned int rating;
      std::cout << "Adding and playing new song" << std::endl;
      std::cout << "Enter song name: ";
      getline(std::cin, s_name);
      std::cout << "Enter song artist: ";
      getline(std::cin, art_name);
      std::cout << "Enter your rating (1-5): ";
      std::cin >> rating;
      songs.insert(it, Songs{s_name, art_name, rating});
      it--;
      std::cout << "Playing:" << std::endl;
      std::cout << *it << std::endl;
    } else if(selection == 'l' || selection == 'L') {
      display(songs, it);
    }

  } while(selection != 'q' && selection != 'Q');

  return 0;
}