#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "algorithm.h"
#include <algorithm>


class QuickSort : public DivideAndConquer {
 public:
  bool small(const std::vector<int>&) const override;
  void solveSmall(const std::vector<int>&) const override;
  void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&) const override;
  void combine(std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const override;
  std::string recurrence() const override;
};

#endif
