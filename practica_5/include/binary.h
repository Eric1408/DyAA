#ifndef BINARY_H
#define BINARY_H

#include "DaC.h"

template <typename T>
class BinarySearch : public DivideAndConquer<T> {
 public:
  BinarySearch();
  std::vector<T> solveSmall(const std::vector<T>&) const override;
  bool small(const std::vector<T>&) const override;
  void divide(const std::vector<T>&, std::vector<std::vector<T>>&) override;
  std::vector<T> combine(const std::vector<T>&, const std::vector<std::vector<T>>&) const override;
};

#endif