#pragma once

#include "algorithm.h"


class Greedy : public Algorithm {
 public:
  Greedy() : Algorithm() {}
  void resolve(const Graph&, std::future<void>) override;
};
