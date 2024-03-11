/**
 * @file main.cc
 * @brief This file contains the implementation of a menu-driven program that performs sorting operations on random vectors.
 *
 * @details The program generates two random vectors, applies MergeSort and QuickSort algorithms on them,
 * and measures the time taken by each algorithm. The sorted vectors and the execution times
 * are then displayed on the console.
 *
 * @date 05-03-2024
 * @author Eric Angueta Rogel
 * @author alu0101335339@ull.edu.es
 * @university Universidad de La Laguna
 */

#include <iostream>

#include "menu.h"
#include "menu2.h"


int main() {
  std::string option;
  std::cout << "choose between [PR-4] and [PR-5]";
  std::cin >> option;

  if (option == "PR-4")
    menu();
  else if (option == "PR-5") {
    menu2();
  }
  
  return 0;
}
    