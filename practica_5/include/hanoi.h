#ifndef HANOI_H
#define HANOI_H

#include "DaC.h"


template <typename T>
class Hanoi : public DivideAndConquer<T> {
 public:
  Hanoi();
  std::vector<T> solveSmall(const std::vector<T>&) override;
  bool small(const std::vector<T>&) const override;
  void divide(const std::vector<T>&, std::vector<std::vector<T>>&, const T& = 0) override;
  std::vector<T> combine(const std::vector<T>&, const std::vector<std::vector<T>>&) const override;
};

#endif