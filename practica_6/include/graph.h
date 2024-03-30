#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Graph {
 public:
  Graph(std::ifstream& file);
  int size() const { return size_; }
  std::vector<int> GetAdj(int i) const { return adj_[i]; }

  // Sobrecarga del operador de indexación
  std::vector<int>& operator[] (int i) { return adj_[i]; }
  const std::vector<int>& operator[] (int i) const { return adj_[i]; }
 
  void showGraph() const;
 private:
  int size_;
  std::vector<std::vector<int>> adj_;
};
