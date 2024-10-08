#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string fileName = "justatest.txt";

class Encoder
{
public:
  std::string encodeString(const std::string &txtToEncode);
  void encodeLines(const std::vector<std::string> &lines, const std::string &fileName);
};

void Encoder::encodeLines(const std::vector<std::string> &lines, const std::string &fileName){
  std::ofstream fileToWrite(fileName, std::ios::trunc);
  std::string encodedLine;
  if(fileToWrite.is_open()){
    if(!lines.empty()){
      for (size_t i = 0; i < lines.size(); i++) {
        encodedLine = encodeString(lines[i]);
        if (i < lines.size() - 1)
          fileToWrite << encodedLine << "\n";
        else
          fileToWrite << encodedLine;
      }
      std::cout << "Successfully encoded and wrote to " << fileName << std::endl;
    } else
        std::cout << "File is empty!" << std::endl;
    fileToWrite.close();
  }
}

std::string Encoder::encodeString(const std::string &txtToEncode)
{
  std::string encoded;
  int counter = 1;

  for(int i = 0; i < txtToEncode.size(); i++){
    if (txtToEncode[i] == txtToEncode[i+1])
      counter++;
    else{
      encoded += std::to_string(counter);
      encoded += txtToEncode[i];
      counter = 1;
    } 
  }
  return encoded;
}

class Decoder {
public:
  std::string decodeString(const std::string &encodedTxt);
  void decodeFile(const std::string &fileName);
};

std::string Decoder::decodeString(const std::string &encodedTxt) {
  std::string decoded;
  std::string number;

  for (size_t i = 0; i < encodedTxt.size(); ++i) {
    if (std::isdigit(encodedTxt[i])) {
      number += encodedTxt[i];
    } else {
      int count = std::stoi(number);
      decoded += std::string(count, encodedTxt[i]);
      number.clear();
    }
  }
  return decoded;
}

void Decoder::decodeFile(const std::string &fileName) {
  std::ifstream fileToRead(fileName);
  std::string decodedContent;

  if (fileToRead.is_open()) {
    std::string line;
    while (getline(fileToRead, line)) {
      std::string decodedLine = decodeString(line);
      decodedContent += decodedLine;
      decodedContent += "\n";
    }
    fileToRead.close();

    if (!decodedContent.empty()) {
      decodedContent.pop_back();
    }

    std::ofstream fileToWrite(fileName, std::ios::trunc);
    if (fileToWrite.is_open()) {
      fileToWrite << decodedContent;
      fileToWrite.close();
      std::cout << "Successfully decoded and wrote back to " << fileName << "." << std::endl;
    } else
      std::cerr << "Failed to open the file for writing: " << fileName << std::endl;
  } else
    std::cerr << "Failed to open the file for reading: " << fileName << std::endl;
}

int selection(){
  int choice;
  std::cout << "Choose an option:\n";
  std::cout << "1. Encode a file\n";
  std::cout << "2. Decode a file\n";
  std::cout << "3. Exit\n";
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  return choice;
}

void encode(){
  Encoder file;
  std::vector<std::string> lines;
  std::ifstream fileToRead;
  fileToRead.open(fileName, std::ios::in);
  if(fileToRead.is_open()){
    std::string line;
    while(getline(fileToRead, line))
      lines.push_back(line);
    fileToRead.close();

    file.encodeLines(lines, fileName);
  }
}

void decode(){
  Decoder dec;
  dec.decodeFile(fileName);
}

int main()
{
  int choice;
  choice = selection();
  if(choice == 1)
    encode();
  else if(choice == 2)
    decode();
  else if(choice == 3)
    exit(0);

  return 0;
}