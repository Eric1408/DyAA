#include "graph.h"

Graph::Graph(std::ifstream& file) {
  std::string line;
  std::getline(file, line);
  size_ = std::stoi(line);
  std::cout << "Size: " << size_ << std::endl;
  adj_.resize(size_);
  for (auto& i : adj_) {
    i.resize(size_);
  }

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    char word1, word2;
    int cost;
    iss >> word1 >> word2 >> cost;
    adj_[word1 - 'A'][word2 - 'A'] = cost;
    
    //std::cout << word1 << " " << word2 << " " << cost << std::endl;
  }
}

void Graph::showGraph() const {
  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      if (adj_[i][j] != 0)
        std::cout << char(i + 'A') << " " << char(j + 'A') << " " << adj_[i][j] << std::endl;
    }
  }
}
