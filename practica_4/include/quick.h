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
class QuickSort : public DivideAndConquer {
 public:
  QuickSort();
  bool small(const std::vector<int>&) const override;
  void solveSmall(std::vector<int>&) const override;
  void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&)  override;
  void combine(std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const override;
};

#endif
