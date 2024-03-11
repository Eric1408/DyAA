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
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>

#include "../include/merge.h"
#include "../include/quick.h"




/**
 * Generates a random vector of integers.
 *
 * @return The randomly generated vector.
 */
template <typename T>
std::vector<T> randomVector() {
  // Initialize random seed
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  // Generate random number between 1 and 100
  int size = std::rand() % 100 + 1;
  //int size = 6;
  
  std::vector<T> data(size);
  for (auto& element : data) {
    element = static_cast<T>(std::rand() % 100 + 1);
  }

  return data;
}



/**
 * Prints the elements of a vector.
 * 
 * @param data The vector to be printed.
 */
template <typename T>
void printVector(std::vector<T>& data) {
  for (auto& c : data) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
}



/**
 * @brief Displays a menu and performs sorting operations on random vectors.
 * 
 * This function displays a menu and performs sorting operations on random vectors.
 * It generates two random vectors, applies MergeSort and QuickSort algorithms on them,
 * and measures the time taken by each algorithm. The sorted vectors and the execution times
 * are then displayed on the console.
 * 
 */
template <typename T>
void menu() {
  char c = 'y';
  while (c == 'y') {
    system("clear");
    std::vector<T> data = randomVector<T>();
    // Wait one second to genereate a new random vector
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::vector<T> data2 = randomVector<T>();

    std::cout << "\x1B[31mRandom Vector 1:\x1B[0m ";
    printVector(data);
    std::cout << "\x1B[31mRandom Vector 2:\x1B[0m ";
    printVector(data2);
    std::cout << std::endl;

    std::vector<T> solution1;
    std::vector<T> solution2;

    // Measure the time for MergeSort
    auto startMerge = std::chrono::high_resolution_clock::now();
    MergeSort<T> mergeSort;
    mergeSort.solve(data);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mergeTime = endMerge - startMerge;

    // Measure the time for QuickSort
    auto startQuick = std::chrono::high_resolution_clock::now();
    QuickSort<T> quickSort;
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
    std::cout << "\x1B[31mMergeSort Time:\x1B[0m " << mergeTime.count() << " milliseconds for a vector size of \x1B[45m[" << data.size() << "]\x1B[0m\n";
    std::cout << "\t" << mergeSort.recurrence() << std::endl;
    mergeSort.showMod();
    std::cout << "\x1B[31mQuickSort Time:\x1B[0m " << quickTime.count() << " milliseconds for a vector size of \x1B[45m[" << data2.size() << "]\x1B[0m\n";
    std::cout << "\t" << quickSort.recurrence() << std::endl;
    quickSort.showMod();
    std::cout << "\nDo u want continue? [y/n]: ";
    std::cin >> c;
  }
}



int main() {
  menu<int>();
  
  return 0;
}
    