#include "../include/quick.h"

template <typename T>
QuickSort<T>::QuickSort() : DivideAndConquer<T>() {
  this->a_ = "";
  this->b_ = " - 1";
  this->d_ = "1";
}

template <typename T>
std::vector<T> QuickSort<T>::solveSmall(std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}

template <typename T>
bool QuickSort<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}

template <typename T>
void QuickSort<T>::divide(const std::vector<T>& input, std::vector<T>& left, std::vector<T>& right) {
  T pivot = input[0];
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

template <typename T>
std::vector<T> QuickSort<T>::combine(std::vector<T>& input, const std::vector<T>& left, const std::vector<T>& right) const {
  T pivot = input[0];
  //input.clear();
  std::vector<T> result;
  
  result = left;
  result.push_back(pivot);
  result.insert(result.end(), right.begin(), right.end());

  return result;
}
