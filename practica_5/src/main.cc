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


int main(int argc, char* argv[]) {
  std::string option{argv[1]};
  if (option == "--normal") {
    menu();
  } else if (option == "--test") {
    int size;
    std::cout << "Choose the vector size: ";
    std::cin >> size;
    menu(size);
  } else {
    std::cerr << "Invalid option. Use --normal or --test." << std::endl;
  }
  
  return 0;
}
    