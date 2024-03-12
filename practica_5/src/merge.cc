#include "../include/merge.h" 

template <typename T>
MergeSort<T>::MergeSort() {
  this->a_ = "2";
  this->b_ = "/2"; 
  this->d_ = "1";
}

template <typename T>
std::vector<T> MergeSort<T>::solveSmall(const std::vector<T>& input) {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}

template <typename T>
bool MergeSort<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}

template <typename T>
void MergeSort<T>::divide(const std::vector<T>& input, std::vector<std::vector<T>>& subp, const T& t) {
  size_t mid = input.size() / 2;

  // Dividir en dos partes, izquierda y derecha
  std::vector<T> leftPart(input.begin(), input.begin() + mid);
  std::vector<T> rightPart(input.begin() + mid, input.end());

  // Agregar las dos partes a subp
  subp.push_back(leftPart);
  subp.push_back(rightPart);
}

template <typename T>
std::vector<T> MergeSort<T>::combine(const std::vector<T>& input, const std::vector<std::vector<T>>& subp) const {
  const std::vector<T>& left = subp[0];
  const std::vector<T>& right = subp[1];

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
