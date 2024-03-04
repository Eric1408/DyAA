#include "../include/quick.h"



/**
 * @brief Constructs a QuickSort object.
 *
 * This constructor initializes the `a_`, `b_`, and `d_` member variables of the QuickSort class.
 * The `a_` variable is initialized as an empty string, the `b_` variable is initialized as "1 - 1",
 * and the `d_` variable is initialized as "1".
 */
QuickSort::QuickSort() : DivideAndConquer() {
  a_ = "";
  b_ = " - 1";
  d_ = "1";
}


/**
 * Sorts a small input vector using the QuickSort algorithm.
 *
 * This function sorts the input vector in ascending order using the QuickSort algorithm.
 * It is intended to be used for small input sizes where the overhead of the QuickSort algorithm is negligible.
 *
 * @param input The input vector to be sorted.
 */
void QuickSort::solveSmall(std::vector<int>& input) const {
  std::vector<int> result = input;
  std::sort(result.begin(), result.end());
  return;
}


/**
 * Checks if the input vector is small enough to be considered sorted.
 * 
 * @param input The input vector to be checked.
 * @return True if the input vector is small (size <= 1), false otherwise.
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
 * Combines the left and right subarrays into the input array.
 * 
 * @param input The input array to be modified.
 * @param left The left subarray.
 * @param right The right subarray.
 */
void QuickSort::combine(std::vector<int>& input, const std::vector<int>& left, const std::vector<int>& right) const {
  int pivot = input[0];
  input.clear();
  input = left;
  input.push_back(pivot);
  input.insert(input.end(), right.begin(), right.end());
  
  return; 
}
