#pragma once 

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

typedef std::vector<std::vector<unsigned>> Matrix;

class Problem {
 private:
  Matrix setupTime_;
  unsigned machines_;
  unsigned taskNumber_;
  std::vector<unsigned> taskTime_;
 public:
  Problem(std::ifstream&);
  friend std::ostream& operator<<(std::ostream&, const Problem&);
};
