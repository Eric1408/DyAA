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
  std::vector<T> solveSmall(const std::vector<T>&) override;
  bool small(const std::vector<T>&) const override;
  void divide(const std::vector<T>&, std::vector<std::vector<T>>&, const T& = 0) override;
  std::vector<T> combine(const std::vector<T>&, const std::vector<std::vector<T>>&) const override;
};

#endif
