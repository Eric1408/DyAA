#include "../include/hanoi.h"

template <typename T>
Hanoi<T>::Hanoi() {
  this->a_ = "";
  this->b_ = " - 1"; 
  this->d_ = "0";
}



template <typename T>
std::vector<T> Hanoi<T>::solveSmall(const std::vector<T>& input) {
  std::vector<T> result = input;
  std::sort(result.begin(), result.end());
  
  return result;
}



template <typename T>
bool Hanoi<T>::small(const std::vector<T>& input) const {
  return input.size() <= 1;
}



template <typename T>
void Hanoi<T>::divide(const std::vector<T>& input, std::vector<std::vector<T>>& subp, const T& t) {
  
}



template <typename T>
std::vector<T> Hanoi<T>::combine(const std::vector<T>& input, const std::vector<std::vector<T>>& subp) const {
  return input; 
}