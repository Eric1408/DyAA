#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class DivideAndConquer {
 public:
  virtual void solve(std::vector<int>&);
  
  virtual bool small(const std::vector<int>&) const = 0;
  virtual void solveSmall(std::vector<int>&) const = 0;
  
  virtual void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&)  = 0;
  virtual void combine(std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const = 0;
  
  virtual std::string recurrence() const;

 protected:
  std::string a_;
  std::string b_;
  std::string d_;
};

#endif
