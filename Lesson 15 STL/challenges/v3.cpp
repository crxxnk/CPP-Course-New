#include <map>
#include <fstream>
#include <iostream>
#include <set>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <deque>

void display_words(const std::map<std::string, int> &words) {
  std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Count" << std::endl;
  std::cout << "=====================================" << std::endl;
  for(auto pair: words)
    std::cout << std::setw(12) << std::left << pair.first << std::setw(7) << std::right << pair.second << std::endl;
}

void display_words(const std::map<std::string, std::set<int>> &words) {
  std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Occurences" << std::endl;
  std::cout << "=====================================" << std::endl;
  for(auto pair: words) {
    std::cout << std::setw(12) << std::left << pair.first << std::left << "[ ";
    for(auto i: pair.second)
      std::cout << i << " ";
    std::cout << "]" << std::endl;
  }
}

std::string clean_string(const std::string &s) {
  std::string result;
  for(char c : s) {
    if(c == ',' || c == '.' || c == ';' || c == ':')
      continue;
    else result += c;
  }
  return result;
}

void part1() {
  std::map<std::string, int> words;
  std::string line;
  std::string word;
  std::ifstream file("words.txt");
  std::deque<std::string> s;
  if(file.is_open()) {
    while(std::getline(file, line)) {
      line = clean_string(line);
      std::stringstream ss(line);
      while(ss>>word)
        words[word]++;
    }
    
    file.close();
    display_words(words);
  } else
      std::cerr << "Error opening file" << std::endl;
}

void part2() {
  std::map<std::string, std::set<int>> words;
  std::string line;
  std::string word;
  std::ifstream file("words.txt");
  int line_count = 0;
  if(file.is_open()) {
    while(std::getline(file, line)) {
      line_count++;
      line = clean_string(line);
      std::stringstream ss(line);
      while(ss>>word) {
        words[word].insert(line_count);
      }
    }
    file.close();
    display_words(words);
  } else
      std::cerr << "Error opening file" << std::endl;
}

int main() {
  part2();

  return 0;
}