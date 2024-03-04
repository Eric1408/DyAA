#include "../include/quickSort.h"



bool QuickSort::small(const std::vector<int>& data) const {
  return data.size() <= 1;
}



void QuickSort::solveSmall(const std::vector<int>& data) const {
  return;
}



void QuickSort::divide(const std::vector<int>& data, std::vector<int>& left, std::vector<int>& right) const  {
  int pivot = data[0];
  
  for (std::size_t i = 1; i < data.size(); ++i) {
    if (data[i] <= pivot) {
      left.push_back(data[i]);
    } else if (data[i] > pivot) {
      right.push_back(data[i]);
    }
  }
  
  //left.push_back(pivot);
}



void QuickSort::combine(std::vector<int>& data, const std::vector<int>& left, const std::vector<int>& right) const {
  data.clear();
  data.insert(data.begin(), left.begin(), left.end());
  data.push_back(data[0]);
  data.insert(data.end(), right.begin(), right.end());
}

/*
void QuickSort::divide(const std::vector<int>& data, std::vector<int>& left, std::vector<int>& right) const {
  int pivot = data[0];
  
  for (std::size_t i = 1; i < data.size(); ++i) {
    if (data[i] < pivot) {
      left.push_back(data[i]);
    } else {
      right.push_back(data[i]);
    }
  }
}



void QuickSort::combine(std::vector<int>& data, const std::vector<int>& left, const std::vector<int>& right) const {
  std::size_t k = 0;

  for (int num : left) {
    data[k++] = num;
  }

  data[k++] = data[0];

  for (int num : right) {
    data[k++] = num;
  }
}
*/


/*
void QuickSort::divide(const std::vector<int>& data, std::vector<int>& left, std::vector<int>& right) const {
  int pivot = data[0];
  
  for (int num : data) {
    if (num < pivot) {
      left.push_back(num);
    } else if (num > pivot) {
      right.push_back(num);
    }
  }
}



void QuickSort::combine(std::vector<int>& data, const std::vector<int>& left, const std::vector<int>& right) const {
  data.clear();
  data.insert(data.begin(), left.begin(), left.end());
  data.push_back(data[0]);
  data.insert(data.end(), right.begin(), right.end());  
}
*/

std::string QuickSort::recurrence() const {
  return "T(n) = T(n - 1) + O(n)";
}
