#ifndef HANOI_H
#define HANOI_H

#include "DaC.h"

template <typename T>
class Hanoi : public DivideAndConquer<T> {
 public:
  Hanoi();
  void solveSmall(std::vector<T>&) const override;
  bool small(const std::vector<T>&) const override;
  void divide(const std::vector<T>&, std::vector<T>&, std::vector<T>&) override;
  void combine(std::vector<T>&, const std::vector<T>&, const std::vector<T>&) const override;
};

#endif