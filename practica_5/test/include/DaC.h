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
  void solve(std::vector<T>&);
  
  virtual bool small(const std::vector<T>&) const = 0;
  virtual void solveSmall(std::vector<T>&) const = 0;
  
  virtual void divide(const std::vector<T>&, std::vector<T>&, std::vector<T>&)  = 0;
  virtual void combine(std::vector<T>&, const std::vector<T>&, const std::vector<T>&) const = 0;
  
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


/**
 * @brief Returns the recurrence equation as a string.
 * 
 * This function returns the recurrence equation in the form of a string.
 * The recurrence equation is of the form T(n) = a*T(n/b) + f(n^d).
 * 
 * @return std::string The recurrence equation as a string.
 */
template <typename T>
std::string DivideAndConquer<T>::recurrence() const {
  return "T(n) = " + a_ + "T(n" + b_ + ") + O(n^" + d_ + ")";
}



/**
 * Solves the problem using the Divide and Conquer algorithm.
 * 
 * @param input The input vector representing the problem.
 */
template <typename T>
void DivideAndConquer<T>::solve(std::vector<T>& input) {
  // Base case: if the problem is small, solve it directly
  if (small(input)) {
    solveSmall(input);
    return; 
  }

  recursiveCalls_++;
  // Divide the problem into subproblems
  std::vector<T> left, right;
  divide(input, left, right);

  level_++;
  if (level_ > maxLevels_) {
    maxLevels_ = level_;
  }
  
  // Recursively solve the subproblems
  solve(left);
  solve(right);

  level_--;
  // Combine the results of the subproblems
  combine(input, left, right);
  
  return; 
}



template <typename T>
void DivideAndConquer<T>::showMod() const {
  std::cout << "\t\x1B[33mMax level reached:\x1B[0m " << maxLevels_ << std::endl;
  std::cout << "\t\x1B[33mNumber of recursive calls:\x1B[0m " << recursiveCalls_ << std::endl;
}

#endif
