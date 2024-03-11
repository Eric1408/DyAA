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
template <typename T>
class MergeSort : public DivideAndConquer<T> {
public:
  MergeSort();
  std::vector<T> solveSmall(std::vector<T>&) const override;
  bool small(const std::vector<T>&) const override;
  void divide(const std::vector<T>&, std::vector<T>&, std::vector<T>&) override;
  std::vector<T> combine(std::vector<T>&, const std::vector<T>&, const std::vector<T>&) const override;
};

#endif