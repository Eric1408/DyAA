#include "../include/binary.h"


template <typename T>
BinarySearch<T>::BinarySearch() {
  this->a_ = "";
  this->b_ = "/2"; 
  this->d_ = "0";
}



template <typename T>
std::vector<T> BinarySearch<T>::solveSmall(const std::vector<T>& input) const {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}



template <typename T>
bool BinarySearch<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}



template <typename T>
void BinarySearch<T>::divide(const std::vector<T>& input, std::vector<std::vector<T>>& subp) {
  
}



template <typename T>
std::vector<T> BinarySearch<T>::combine(const std::vector<T>& input, const std::vector<std::vector<T>>& subproblems) const {
  std::vector<T> combinedResult = input;

  for (const auto& subproblemResult : subproblems) {
    // Realiza la combinación de los resultados de los subproblemas según tu lógica específica
    size_t i = 0, j = 0;
    size_t subproblemIndex = 0;

    while (i < combinedResult.size() && j < subproblemResult.size()) {
      if (combinedResult[i] < subproblemResult[j]) {
        combinedResult[subproblemIndex++] = combinedResult[i++];
      } else {
        combinedResult[subproblemIndex++] = subproblemResult[j++];
      }
    }

    while (i < combinedResult.size()) {
      combinedResult[subproblemIndex++] = combinedResult[i++];
    }

    while (j < subproblemResult.size()) {
      combinedResult[subproblemIndex++] = subproblemResult[j++];
    }

    // Actualiza el tamaño del resultado combinado después de la fusión
    combinedResult.resize(subproblemIndex);
  }

  return combinedResult; 
}
