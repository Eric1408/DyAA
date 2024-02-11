#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Tape {
 public:
  Tape() : position_(0) {}

  void moveRight();
  
  virtual ~Tape() = default;
 
 protected:
  size_t position_;
  std::vector<int> data_;
};

class InputTape : public Tape {
 public:
  InputTape(const std::string&);
};

class OutputTape : public Tape {
 public:
  OutputTape(const std::string&);
};
