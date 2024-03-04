#include "../include/DaC.h"



/**
 * @brief Returns the recurrence equation as a string.
 * 
 * This function returns the recurrence equation in the form of a string.
 * The recurrence equation is of the form T(n) = a*T(n/b) + f(n^d).
 * 
 * @return std::string The recurrence equation as a string.
 */
std::string DivideAndConquer::recurrence() const {
  return "T(n) = " + a_ + "T(n" + b_ + ") + O(n^" + d_ + ")";
}



/**
 * Solves the problem using the Divide and Conquer algorithm.
 * 
 * @param input The input vector representing the problem.
 */
void DivideAndConquer::solve(std::vector<int>& input) {
  // Base case: if the problem is small, solve it directly
  if (small(input)) {
    solveSmall(input);
    return; 
  }

  // Divide the problem into subproblems
  std::vector<int> left, right;
  divide(input, left, right);

  // Recursively solve the subproblems
  solve(left);
  solve(right);

  // Combine the results of the subproblems
  combine(input, left, right);
  return; 
}
