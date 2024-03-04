#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>

class DivideAndConquer {
 public:
  virtual std::vector<int> solve(const std::vector<int>&);
  
  virtual bool small(const std::vector<int>&) const = 0;
  virtual std::vector<int> solveSmall(const std::vector<int>&) const = 0;
  
  virtual void divide(const std::vector<int>&, std::vector<int>&, std::vector<int>&)  = 0;
  virtual std::vector<int> combine(const std::vector<int>&, const std::vector<int>&, const std::vector<int>&) const = 0;
  
  virtual std::string recurrence() const;

 protected:
  std::string a_;
  std::string b_;
  std::string d_;
};

#endif
