#include "../include/binary.h"


template <typename T>
BinarySearch<T>::BinarySearch() : DivideAndConquer<T>() {
  this->a_ = "";
  this->b_ = "/2"; 
  this->d_ = "0";
}



template <typename T>
std::vector<T> BinarySearch<T>::solveSmall(std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}



template <typename T>
bool BinarySearch<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}



template <typename T>
void BinarySearch<T>::divide(const std::vector<T>& input, std::vector<T>& left, std::vector<T>& right) {
  int mid = input.size() / 2;
  left.assign(input.begin(), input.begin() + mid);
  right.assign(input.begin() + mid, input.end());
}



template <typename T>
std::vector<T> BinarySearch<T>::combine(std::vector<T>& input, const std::vector<T>& left, const std::vector<T>& right) const {
  size_t i = 0, j = 0;
  
  std::vector<T> result;
  
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
