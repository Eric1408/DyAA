#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>

#include "mergeSort.h"
#include "quickSort.h"



std::vector<int> randomVector() {
  // Initialize random seed
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  // Generate random number between 1 and 100
  int size = std::rand() % 100 + 1;

  std::vector<int> data(size);
  for (auto& c : data) {
    c = std::rand() % 100 + 1;
  }

  return data;
}



void printVector(std::vector<int>& data) {
  for (auto& c : data) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
}



void menu() {
  while (true) {
    std::vector<int> data = randomVector();
    std::vector<int> data2 = randomVector();

    printVector(data);
    printVector(data2);
    std::cout << std::endl;

    // Medir el tiempo para MergeSort
    auto startMerge = std::chrono::high_resolution_clock::now();
    MergeSort mergeSort;
    mergeSort.solve(data);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeTime = endMerge - startMerge;

    // Medir el tiempo para QuickSort
    auto startQuick = std::chrono::high_resolution_clock::now();
    QuickSort quickSort;
    quickSort.solve(data2);
    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quickTime = endQuick - startQuick;

    // Imprimir los tiempos
    std::cout << "MergeSort Time: " << mergeTime.count() << " seconds" << std::endl;
    std::cout << "QuickSort Time: " << quickTime.count() << " seconds" << std::endl;

    printVector(data);
    printVector(data2);
  }
}



int main() {
  menu();
  
  return 0;
}
    