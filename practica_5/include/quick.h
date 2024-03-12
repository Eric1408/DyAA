#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "DaC.h"


/**
 * @class QuickSort
 * @brief A class that implements the QuickSort algorithm using the Divide and Conquer strategy.
 * 
 * The QuickSort class inherits from the DivideAndConquer class and provides implementations for the
 * virtual functions defined in the base class.
 */
template <typename T>
class QuickSort : public DivideAndConquer<T> {
 public:
  QuickSort();
  bool small(const std::vector<T>&) const override;
  std::vector<T> solveSmall(const std::vector<T>&) override;
  void divide(const std::vector<T>&, std::vector<std::vector<T>>&, const T& = 0) override;
  std::vector<T> combine(const std::vector<T>&, const std::vector<std::vector<T>>&) const override;
};

#endif
