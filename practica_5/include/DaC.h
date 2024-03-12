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
  std::vector<T> solve(const std::vector<T>&, const T = 0);
  static void Hanoi(int, char, char, char);

  virtual bool small(const std::vector<T>&) const = 0;
  virtual std::vector<T> solveSmall(const std::vector<T>&) const = 0;
  
  virtual void divide(const std::vector<T>&, std::vector<std::vector<T>>&)  = 0;
  virtual std::vector<T> combine(const std::vector<T>&, const std::vector<std::vector<T>>&) const = 0;
  
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
