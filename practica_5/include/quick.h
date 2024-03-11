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
  std::vector<T> solveSmall(std::vector<T>&) const override;
  void divide(const std::vector<T>&, std::vector<T>&, std::vector<T>&)  override;
  std::vector<T> combine(std::vector<T>&, const std::vector<T>&, const std::vector<T>&) const override;
};

#endif
