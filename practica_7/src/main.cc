#include <iostream>
#include <fstream>

#include "problem.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }  

  std::ifstream file(argv[1]);

  Problem problem(file);
  std::cout << problem;

  return 0;
}
