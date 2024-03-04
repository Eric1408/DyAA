#include "../include/DaC.h"

std::string DivideAndConquer::recurrence() const {
  return "T(n) = " + a_ + "T(n/b) + " + b_ + "f(n) + " + d_;
}

std::vector<int> DivideAndConquer::solve(const std::vector<int>& input) {
  // Base case: if the problem is small, solve it directly
  if (small(input)) {
    return solveSmall(input);
  }

  // Divide the problem into subproblems
  std::vector<int> left, right;
  divide(input, left, right);

  // Recursively solve the subproblems
  std::vector<int> leftResult = solve(left);
  std::vector<int> rightResult = solve(right);

  // Combine the results of the subproblems
  return combine(input, leftResult, rightResult);
}
