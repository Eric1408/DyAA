#include "../include/hanoi.h"

template <typename T>
Hanoi<T>::Hanoi() {
  this->a_ = "";
  this->b_ = " - 1"; 
  this->d_ = "0";
}



template <typename T>
std::vector<T> Hanoi<T>::solveSmall(std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}



template <typename T>
bool Hanoi<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}



template <typename T>
void Hanoi<T>::divide(const std::vector<T>& input, std::vector<T>& left, std::vector<T>& right) {
  int mid = input.size() / 2;
  left.assign(input.begin(), input.begin() + mid);
  right.assign(input.begin() + mid, input.end());
}



template <typename T>
std::vector<T> Hanoi<T>::combine(std::vector<T>& input, const std::vector<T>& left, const std::vector<T>& right) const {
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