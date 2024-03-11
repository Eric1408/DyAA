#include "../include/quick.h"

template <typename T>
QuickSort<T>::QuickSort() : DivideAndConquer<T>() {
  //a_ = "";
  //b_ = " - 1";
  //d_ = "1";
}

template <typename T>
void QuickSort<T>::solveSmall(std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  return;
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
void QuickSort<T>::combine(std::vector<T>& input, const std::vector<T>& left, const std::vector<T>& right) const {
  T pivot = input[0];
  input.clear();
  input = left;
  input.push_back(pivot);
  input.insert(input.end(), right.begin(), right.end());

  return;
}
