#include "algorithm.h"


void Algorithm::PrintPath() const {
  for (int i = 0; i < path_.size(); i++) {
    std::cout << char(path_[i] + 'A') << " ";
  }
  std::cout << std::endl;
}

int Algorithm::GetMinVal() const {
  return minVal_;
}
