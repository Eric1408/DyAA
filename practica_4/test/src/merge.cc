#include "../include/merge.h"



/**
 * @brief Performs a small size merge sort on the input vector.
 * 
 * This function takes an input vector of integers and returns a sorted vector using merge sort algorithm.
 * 
 * @param input The input vector of integers.
 * @return The sorted vector.
 */
std::vector<int> MergeSort::solveSmall(const std::vector<int>& input) const {
  return input;
}



/**
 * Checks if the input vector is small.
 * 
 * @param input The input vector to be checked.
 * @return True if the input vector is small (size <= 1), false otherwise.
 */
bool MergeSort::small(const std::vector<int>& input) const {
  return input.size() <= 1;
}



/**
 * Divides the input vector into two halves.
 * 
 * @param input The input vector to be divided.
 * @param left The vector to store the left half of the input.
 * @param right The vector to store the right half of the input.
 */
void MergeSort::divide(const std::vector<int>& input, std::vector<int>& left, std::vector<int>& right) {
  int mid = input.size() / 2;
  left.assign(input.begin(), input.begin() + mid);
  right.assign(input.begin() + mid, input.end());
}



/**
 * @brief Combines two sorted vectors into a single sorted vector.
 * 
 * This function takes two sorted vectors, `left` and `right`, and combines them into a single sorted vector.
 * The resulting vector will contain all the elements from both `left` and `right`, and will be sorted in ascending order.
 * 
 * @param left The first sorted vector.
 * @param right The second sorted vector.
 * @return The combined sorted vector.
 */
std::vector<int> MergeSort::combine(const std::vector<int>& input, const std::vector<int>& left, const std::vector<int>& right) const {
  std::vector<int> result;
  size_t i = 0, j = 0;

  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      result.push_back(left[i]);
      ++i;
    } else {
      result.push_back(right[j]);
      ++j;
    }
  }

  result.insert(result.end(), left.begin() + i, left.end());
  result.insert(result.end(), right.begin() + j, right.end());

  return result;
}
