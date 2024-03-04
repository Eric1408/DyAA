#include "../include/merge.h"



/**
 * @brief Constructs a MergeSort object.
 * 
 * This constructor initializes the MergeSort object by calling the base class constructor
 * and setting the values of member variables a_, b_, and d_.
 */
MergeSort::MergeSort() : DivideAndConquer() {
  a_ = "2";
  b_ = "/2"; 
  d_ = "1";
}



/**
 * Sorts a small input vector using the merge sort algorithm.
 *
 * @param input The input vector to be sorted.
 */
void MergeSort::solveSmall(std::vector<int>& input) const {
  std::vector<int> result = input;
  std::sort(result.begin(), result.end());
  return;
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
 * Combines two sorted vectors into one sorted vector.
 * 
 * @param input The vector to store the combined sorted elements.
 * @param left The left vector to be combined.
 * @param right The right vector to be combined.
 */
void MergeSort::combine(std::vector<int>& input, const std::vector<int>& left, const std::vector<int>& right) const {
  //std::vector<int> result;
  size_t i = 0, j = 0;
  input.clear();
  
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      input.push_back(left[i]);
      ++i;
    } else {
      input.push_back(right[j]);
      ++j;
    }
  }

  input.insert(input.end(), left.begin() + i, left.end());
  input.insert(input.end(), right.begin() + j, right.end());


  return; 
}
