#include "../include/DaC.h"



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
std::vector<T> DivideAndConquer<T>::solve(std::vector<T>& input) {
  // Base case: if the problem is small, solve it directly
  if (small(input)) {
    solveSmall(input);
    return input; 
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
  std::vector<T> leftSolved = solve(left);
  std::vector<T> rightSolved = solve(right); 

  level_--;
  // Combine the results of the subproblems
  
  return combine(input, leftSolved, rightSolved); 
}



template <typename T>
void DivideAndConquer<T>::showMod() const {
  std::cout << "\t\x1B[33mMax level reached:\x1B[0m " << maxLevels_ << std::endl;
  std::cout << "\t\x1B[33mNumber of recursive calls:\x1B[0m " << recursiveCalls_ << std::endl;
}