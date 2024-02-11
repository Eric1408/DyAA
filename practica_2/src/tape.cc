#include "../include/tape.h"

void Tape::moveRight() {
  if(position_ < data_.size() -1) position_++;
}

InputTape::InputTape(const std::string& filename) {
  std::ifstream input_file(filename);

  int value;
  while(input_file >> value) {
    data_.push_back(value);
  }
  input_file.close();
  position_ = 0;
}

OutputTape::OutputTape(const std::string& filename) {
  std::ofstream output_file(filename);

  
}
