#include <algorithm>

#include "../include/quick.h"



/**
 * @brief Solves the problem for small input vectors.
 * @param input The input vector.
 * @return The sorted vector.
 */    
std::vector<int> QuickSort::solveSmall(const std::vector<int>& input) const {
  std::vector<int> result = input;
  std::sort(result.begin(), result.end());
  return result;
}


/**
 * @brief Checks if the input vector is small enough to be solved directly.
 * @param input The input vector.
 * @return True if the vector is small enough, false otherwise.
 */
bool QuickSort::small(const std::vector<int>& input) const {
  return input.size() <= 1;
}



/**
 * Divides the input vector into two separate vectors, left and right, based on a pivot element.
 * Elements smaller than the pivot are added to the left vector, while elements greater than or equal to the pivot are added to the right vector.
 * 
 * @param input The input vector to be divided.
 * @param left The vector to store elements smaller than the pivot.
 * @param right The vector to store elements greater than or equal to the pivot.
 */
void QuickSort::divide(const std::vector<int>& input, std::vector<int>& left, std::vector<int>& right)  {
  int pivot = input[0];
  left.clear();
  right.clear();

  for (size_t i = 1; i < input.size(); ++i) {
    if (input[i] <= pivot) {
      left.push_back(input[i]);
    } else {
      right.push_back(input[i]);
    }
  }
}



/**
 * Combines two vectors into a single vector.
 *
 * @param left The first vector.
 * @param right The second vector.
 * @return The combined vector.
 */
std::vector<int> QuickSort::combine(const std::vector<int>& input,const std::vector<int>& left, const std::vector<int>& right) const {
  std::vector<int> result = left;
  result.push_back(input[0]);
  result.insert(result.end(), right.begin(), right.end());
  
  return result;
}
