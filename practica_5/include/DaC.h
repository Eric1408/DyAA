#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


template <typename T>
class DivideAndConquer {
 public:
  DivideAndConquer() : level_{1}, maxLevels_{1}, recursiveCalls_{0} {}
  std::vector<T> solve(std::vector<T>&);
  
  virtual bool small(const std::vector<T>&) const = 0;
  virtual std::vector<T> solveSmall(std::vector<T>&) const = 0;
  
  virtual void divide(const std::vector<T>&, std::vector<T>&, std::vector<T>&)  = 0;
  virtual std::vector<T> combine(std::vector<T>&, const std::vector<T>&, const std::vector<T>&) const = 0;
  
  virtual std::string recurrence() const;

  void showMod() const;

 protected:
  std::string a_;
  std::string b_;
  std::string d_;

  // MODIF
  int level_;
  int maxLevels_;
  int recursiveCalls_;
};

#endif
