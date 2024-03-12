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
std::vector<T> DivideAndConquer<T>::solve(const std::vector<T>& input, const T target) {
  // Base case: if the problem is small, solve it directly
  if (small(input)) {
    solveSmall(input);
    return input; 
  }

  recursiveCalls_++;
 
  // Divide the problem into subproblems
  std::vector<std::vector<T>> subproblems;
  divide(input, subproblems, target);

  level_++;
  if (level_ > maxLevels_) {
    maxLevels_ = level_;
  }

  // Recursively solve the subproblems
  std::vector<std::vector<T>> subproblemsSolved;
  for (const auto& subproblem : subproblems) {
    subproblemsSolved.push_back(solve(subproblem, target));
  }

  level_--;
  // Combine the results of the subproblems
  
  return combine(input, subproblemsSolved); 
}


template <typename T>
bool DivideAndConquer<T>::Binary(const std::vector<T>& input, const T target, const int low, const int high) {
  if (low > high) return false;
  int mid = low + (high - low) / 2;
  if (input[mid] == target) return true;
  if (input[mid] > target) return Binary(input, target, low, mid - 1);
  return Binary(input, target, mid + 1, high);
}


template <typename T>
void DivideAndConquer<T>::Hanoi(int n, char from, char to, char aux) {
  if (n == 0) return;
  if (n == 1) {
    std::cout << "Move disk 1 from rod " << from << " to rod " << to << std::endl;
    return;
  }
  Hanoi(n - 1, from, aux, to);
  std::cout << "Move disk " << n << " from rod " << from << " to rod " << to << std::endl;
  Hanoi(n - 1, aux, to, from);
}

// MODIFICATION
template <typename T>
void DivideAndConquer<T>::showMod() const {
  std::cout << "\t\x1B[33mMax level reached:\x1B[0m " << maxLevels_ << std::endl;
  std::cout << "\t\x1B[33mNumber of recursive calls:\x1B[0m " << recursiveCalls_ << std::endl;
}