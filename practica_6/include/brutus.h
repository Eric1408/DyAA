#pragma once 

#include <algorithm>
#include "algorithm.h"


class Brutus : public Algorithm {
 public:
  Brutus() : Algorithm() {}
  void resolve(const Graph&, std::future<void>) override;
  int calculateCost(const std::vector<int>&, const Graph&);
};
