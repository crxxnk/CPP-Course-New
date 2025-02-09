#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s) {
  std::deque<char> str(s.size());
  for(int i = 0; i < s.size(); i++) {
    str.at(i) = toupper(s.at(i));
    if(char(str.front() + i / s.size()) == char(str.back() - i / s.size()))
      return true;
  }

  return false;
}

int main() {
  std::vector<std::string> test_strings{"a","aa","aba","abba","abbcbba","ab","abc","radar","bob","ana",
  "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA",
  "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canalPanama", "This is a palindrome", "palindrome"};

  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
  for(const auto &s : test_strings) {
    std::cout << std::setw(8) << std::left << is_palindrome(s) << std::endl; 
  }
  std::cout << std::endl;

  return 0;
}