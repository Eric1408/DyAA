#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>

class DivideAndConquer {
 public:
  virtual void solve(std::vector<int>&);
  
  virtual bool small(const std::vector<int>&) const = 0;
  virtual void solveSmall(const std::vector<int>&) const = 0;
  
  virtual void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&) const = 0;
  virtual void combine(std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const = 0;
  
  virtual std::string recurrence() const = 0;
};

#endif
