#pragma once

#include "graph.h"

#include <vector>
#include <future>
#include <chrono>
#include <limits>
#include <iostream>

const int INF = std::numeric_limits<int>::max();

class Algorithm {
 public:
  Algorithm() : minVal_(INF), excesive_(false) {}
  int GetMinVal() const;
  void PrintPath() const;
  virtual void resolve(const Graph&, std::future<void>) = 0;
  std::chrono::milliseconds getTime() const { return executionTime; }
  std::chrono::milliseconds getExecutionTime() const { return executionTime; }
 
 protected:
  int minVal_;
  bool excesive_;
  std::vector<int> path_;
  std::chrono::milliseconds executionTime;
};

