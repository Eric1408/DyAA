#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "DaC.h"
#include <iostream>


/**
 * @class QuickSort
 * @brief A class that implements the QuickSort algorithm using the Divide and Conquer strategy.
 * 
 * The QuickSort class inherits from the DivideAndConquer class and provides implementations for the
 * virtual functions defined in the base class.
 */
class QuickSort : public DivideAndConquer {
 public:
  bool small(const std::vector<int>&) const override;
  std::vector<int> solveSmall(const std::vector<int>&) const override;
  void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&)  override;
  std::vector<int> combine(const std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const override;
};

#endif
