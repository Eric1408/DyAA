#include "../include/quick.h"

template <typename T>
QuickSort<T>::QuickSort() {
  this->a_ = "";
  this->b_ = " - 1";
  this->d_ = "1";
}

template <typename T>
std::vector<T> QuickSort<T>::solveSmall(const std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}

template <typename T>
bool QuickSort<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}

template <typename T>
void QuickSort<T>::divide(const std::vector<T>& input, std::vector<std::vector<T>>& subproblems) {
  T pivot = input[0];
  std::vector<T> equal, less, greater;

  for (const T& element : input) {
    if (element < pivot) {
      less.push_back(element);
    } else if (element > pivot) {
      greater.push_back(element);
    } else {
      equal.push_back(element);
    }
  }

  subproblems.push_back(less);
  subproblems.push_back(equal);
  subproblems.push_back(greater);
}

template <typename T>
std::vector<T> QuickSort<T>::combine(const std::vector<T>& input, const std::vector<std::vector<T>>& subproblems) const {
  if (subproblems.size() != 3) {
    // Manejar caso inesperado (no se dividió correctamente en 3 subproblemas)
    // Puedes lanzar una excepción o manejar de otra manera según tus necesidades
    std::cout << "Error en quick no se dividio en 3\n";
    return input;
  }

  const std::vector<T>& less = subproblems[0];
  const std::vector<T>& equal = subproblems[1];
  const std::vector<T>& greater = subproblems[2];

  // Concatena los subproblemas ordenados
  std::vector<T> result;
  result.insert(result.end(), less.begin(), less.end());
  result.insert(result.end(), equal.begin(), equal.end());
  result.insert(result.end(), greater.begin(), greater.end());

  return result;
}
