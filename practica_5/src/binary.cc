#include "../include/binary.h"


template <typename T>
BinarySearch<T>::BinarySearch() {
  this->a_ = "";
  this->b_ = "/2"; 
  this->d_ = "0";
}



template <typename T>
std::vector<T> BinarySearch<T>::solveSmall(const std::vector<T>& input) {
  std::vector<T> result;;
  
  return result;
}



template <typename T>
bool BinarySearch<T>::small(const std::vector<T>& input) const {
  return input.size() <= 2;
}



template <typename T>
void BinarySearch<T>::divide(const std::vector<T>& input, std::vector<std::vector<T>>& subp, const T& target) {
  size_t low = 0;
  size_t high = input.size() - 1;
  size_t mid = 0;

  // Búsqueda binaria para encontrar la posición del objetivo
  while (low <= high) {
    mid = low + (high - low) / 2;

    if (input[mid] == target) {
      found_ = true;
      break;
    } else if (input[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  // Dividir el vector en dos partes: izquierda y derecha
  std::vector<T> left(input.begin(), input.begin() + mid);
  std::vector<T> right(input.begin() + mid + 1, input.end());

  subp.push_back(left);
  subp.push_back(right);
}



template <typename T>
std::vector<T> BinarySearch<T>::combine(const std::vector<T>& input, const std::vector<std::vector<T>>& subproblems) const {
  return input;  
}
