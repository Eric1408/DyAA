#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>

#include "../include/merge.h"
#include "../include/quick.h"



std::vector<int> randomVector() {
  // Initialize random seed
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  // Generate random number between 1 and 100
  //int size = std::rand() % 10 + 1;
  int size = 6;

  std::vector<int> data(size);
  for (auto& c : data) {
    c = std::rand() % 10 + 1;
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
  char c = 'y';
  while (c == 'y') {
    std::vector<int> data = randomVector();
    // Wait one second to genereate a new random vector
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::vector<int> data2 = randomVector();

    std::cout << "Random Vector 1: ";
    printVector(data);
    std::cout << "Random Vector 2: ";
    printVector(data2);
    std::cout << std::endl;

    std::vector<int> solution1;
    std::vector<int> solution2;

    // Measure the time for MergeSort
    auto startMerge = std::chrono::high_resolution_clock::now();
    MergeSort mergeSort;
    solution1 = mergeSort.solve(data);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeTime = endMerge - startMerge;

    // Measure the time for QuickSort
    auto startQuick = std::chrono::high_resolution_clock::now();
    QuickSort quickSort;
    solution2 = quickSort.solve(data2);
    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quickTime = endQuick - startQuick;

    std::cout << "Vector Solved 1: ";
    printVector(solution1);
    std::cout << "Vector Solved 2: ";
    printVector(solution2);
    std::cout << std::endl;

    // Print times
    std::cout << "MergeSort Time: " << mergeTime.count() << " seconds for a vector size of [" << data.size() << "]\n";
    std::cout << "QuickSort Time: " << quickTime.count() << " seconds for a vector size of [" << data2.size() << "]\n";
    std::cout << "\nDo u want continue? [y/n]: ";
    std::cin >> c;
    system("clear");
  }
}



int main() {
  menu();
  
  return 0;
}
    