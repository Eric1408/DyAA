#include "../include/merge.h" 

template <typename T>
MergeSort<T>::MergeSort() : DivideAndConquer<T>() {
  //a_ = "2";
  //b_ = "/2"; 
  //d_ = "1";
}

template <typename T>
void MergeSort<T>::solveSmall(std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  return;
}

template <typename T>
bool MergeSort<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}

template <typename T>
void MergeSort<T>::divide(const std::vector<T>& input, std::vector<T>& left, std::vector<T>& right) {
  int mid = input.size() / 2;
  left.assign(input.begin(), input.begin() + mid);
  right.assign(input.begin() + mid, input.end());
}

template <typename T>
void MergeSort<T>::combine(std::vector<T>& input, const std::vector<T>& left, const std::vector<T>& right) const {
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
