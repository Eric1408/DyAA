#include "../include/mergeSort.h"



bool MergeSort::small(const std::vector<int>& data) const {
  return data.size() <= 1;
}



void MergeSort::solveSmall(const std::vector<int>& data) const {
  return;
}



void MergeSort::divide(const std::vector<int>& data, std::vector<int>& left, std::vector<int>& right) const {
  int mid = data.size() / 2;
  left = std::vector<int>(data.begin(), data.begin() + mid);
  right = std::vector<int>(data.begin() + mid, data.end());
}



void MergeSort::combine(std::vector<int>& data, const std::vector<int>& left, const std::vector<int>& right) const {
  std::size_t i = 0, j = 0, k = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      data[k] = left[i];
      i++;
    } else {
      data[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < left.size()) {
    data[k] = left[i];
    i++;
    k++;
  }

  while (j < right.size()) {
    data[k] = right[j];
    j++;
    k++;
  }
}



std::string MergeSort::recurrence() const {
  return "T(n) = 2T(n/2) + O(n)";
}