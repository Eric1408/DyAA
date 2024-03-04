#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "DaC.h"

/**
 * @class MergeSort
 * @brief A class that implements the Merge Sort algorithm using the Divide and Conquer technique.
 * 
 * The MergeSort class inherits from the DivideAndConquer class and provides implementations for the
 * solveSmall, small, divide, and combine methods.
 */
class MergeSort : public DivideAndConquer {
public:
  MergeSort();
  void solveSmall(std::vector<int>&) const override;
  bool small(const std::vector<int>&) const override;
  void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&) override;
  void combine(std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const override;
};

#endif
