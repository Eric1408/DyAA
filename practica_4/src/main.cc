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
  char c = 'y';
  while (c == 'y') {
    system("clear");
    std::vector<int> data = randomVector();
    // Wait one second to genereate a new random vector
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::vector<int> data2 = randomVector();

    std::cout << "\x1B[31mRandom Vector 1:\x1B[0m ";
    printVector(data);
    std::cout << "\x1B[31mRandom Vector 2:\x1B[0m ";
    printVector(data2);
    std::cout << std::endl;

    std::vector<int> solution1;
    std::vector<int> solution2;

    // Measure the time for MergeSort
    auto startMerge = std::chrono::high_resolution_clock::now();
    MergeSort mergeSort;
    mergeSort.solve(data);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mergeTime = endMerge - startMerge;

    // Measure the time for QuickSort
    auto startQuick = std::chrono::high_resolution_clock::now();
    QuickSort quickSort;
    quickSort.solve(data2);
    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> quickTime = endQuick - startQuick;

    //std::cout << "Vector Solved 1: ";
    std::cout << "\x1B[31mSolved Vector 1:\x1B[0m ";
    printVector(data);
    std::cout << "\x1B[31mSolved Vector 2:\x1B[0m ";
    printVector(data2);
    std::cout << std::endl;

    // Print times
    std::cout << "\x1B[31mMergeSort Time:\x1B[0m " << mergeTime.count() << " seconds for a vector size of \x1B[45m[" << data.size() << "]\x1B[0m\n";
    std::cout << "\t" << mergeSort.recurrence() << std::endl;
    std::cout << "\x1B[31mQuickSort Time:\x1B[0m " << quickTime.count() << " seconds for a vector size of \x1B[45m[" << data2.size() << "]\x1B[0m\n";
    std::cout << "\t" << quickSort.recurrence() << std::endl;
    std::cout << "\nDo u want continue? [y/n]: ";
    std::cin >> c;
  }
}



int main() {
  menu();
  
  return 0;
}
    