#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>

#include "../include/menu.h"

#include "merge.cc"
#include "quick.cc"
#include "DaC.cc"

const int SIZE = 10;

/**
 * Generates a random vector of integers.
 *
 * @return The randomly generated vector.
 */
std::vector<int> randomIntVector() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  int size = std::rand() % SIZE + 1;
  std::vector<int> data(SIZE);
  for (auto& element : data) {
    element = std::rand() % SIZE;
  }

  return data;
}



/**
 * Generates a random vector of floats.
 *
 * @return The randomly generated vector.
 */
std::vector<float> randomFloatVector() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  int size = std::rand() % SIZE + 1;
  std::vector<float> data(SIZE);
  for (auto& element : data) {
    element = static_cast<float>(std::rand()) / static_cast<float>(SIZE);
  }

  return data;
}



/**
 * Generates a random vector of chars.
 *
 * @return The randomly generated vector.
 */
std::vector<char> randomCharVector() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  int size = std::rand() % SIZE + 1;
  std::vector<char> data(SIZE);
  for (auto& element : data) {
    element = static_cast<char>('A' + std::rand() % 26);  // Generating uppercase letters
  }
  
  return data;
}



/**
 * Prints the elements of a vector.
 * 
 * @param data The vector to be printed.
 */
template <typename T>
void printVector(const std::vector<T>& data) {
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
void menu() {
  char c = 'y';
  while (c == 'y') {
    system("clear");
    
    // Data Type selection
    std::string type;
    std::cout << "Choose a data type [int, char, float]\n";
    std::cin >> type;

    if (type == "int") {
      // Generate random vectors
      std::vector<int> data = randomIntVector();
      std::vector<int> data2 = randomIntVector();
      
      // Print random vectors
      std::cout << "\x1B[31mRandom Vector 1:\x1B[0m ";
      printVector(data);
      std::cout << "\x1B[31mRandom Vector 2:\x1B[0m ";
      printVector(data2);
      std::cout << std::endl;

      std::vector<int> solution1;
      std::vector<int> solution2;

      // Measure the time for MergeSort
      auto startMerge = std::chrono::high_resolution_clock::now();
      MergeSort<int> mergeSort;
      solution1 = mergeSort.solve(data);
      auto endMerge = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> mergeTime = endMerge - startMerge;

      // Measure the time for QuickSort
      auto startQuick = std::chrono::high_resolution_clock::now();
      QuickSort<int> quickSort;
      solution2= quickSort.solve(data2);
      auto endQuick = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> quickTime = endQuick - startQuick;
    
      // Print sorted vectors
      std::cout << "\x1B[31mSolved Vector 1:\x1B[0m ";
      printVector(solution1);
      std::cout << "\x1B[31mSolved Vector 2:\x1B[0m ";
      printVector(solution2);
      std::cout << std::endl;

      // Print times and recurrence
      std::cout << "\x1B[31mMergeSort Time:\x1B[0m " << mergeTime.count() << " milliseconds for a vector size of \x1B[45m[" 
                << solution1.size() << "]\x1B[0m\n";
      std::cout << "\t" << mergeSort.recurrence() << std::endl;
      mergeSort.showMod();
      std::cout << "\x1B[31mQuickSort Time:\x1B[0m " << quickTime.count() << " milliseconds for a vector size of \x1B[45m[" 
                << solution2.size() << "]\x1B[0m\n";
      std::cout << "\t" << quickSort.recurrence() << std::endl;
      quickSort.showMod();
    
    } else if (type == "float") {
      // Genereta random vectors
      std::vector<float> data = randomFloatVector();
      std::vector<float> data2 = randomFloatVector();

      // Print random vectors
      std::cout << "\x1B[31mRandom Vector 1:\x1B[0m ";
      printVector(data);
      std::cout << "\x1B[31mRandom Vector 2:\x1B[0m ";
      printVector(data2);
      std::cout << std::endl;

      std::vector<float> solution1;
      std::vector<float> solution2;

      // Measure the time for MergeSort
      auto startMerge = std::chrono::high_resolution_clock::now();
      MergeSort<float> mergeSort;
      solution1 = mergeSort.solve(data);
      auto endMerge = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> mergeTime = endMerge - startMerge;

      // Measure the time for QuickSort
      auto startQuick = std::chrono::high_resolution_clock::now();
      QuickSort<float> quickSort;
      solution2 = quickSort.solve(data2);
      auto endQuick = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> quickTime = endQuick - startQuick;
      
      // Print sorted vectors
      std::cout << "\x1B[31mSolved Vector 1:\x1B[0m ";
      printVector(solution1);
      std::cout << "\x1B[31mSolved Vector 2:\x1B[0m ";
      printVector(solution2);
      std::cout << std::endl;

      // Print times
      std::cout << "\x1B[31mMergeSort Time:\x1B[0m " << mergeTime.count() << " milliseconds for a vector size of \x1B[45m[" 
                << data.size() << "]\x1B[0m\n";
      std::cout << "\t" << mergeSort.recurrence() << std::endl;
      mergeSort.showMod();
      std::cout << "\x1B[31mQuickSort Time:\x1B[0m " << quickTime.count() << " milliseconds for a vector size of \x1B[45m[" 
                << data2.size() << "]\x1B[0m\n";
      std::cout << "\t" << quickSort.recurrence() << std::endl;
      quickSort.showMod();
    
    } else if (type == "char") {
      std::vector<char> data = randomCharVector();
      std::vector<char> data2 = randomCharVector();

      std::cout << "\x1B[31mRandom Vector 1:\x1B[0m ";
      printVector(data);
      std::cout << "\x1B[31mRandom Vector 2:\x1B[0m ";
      printVector(data2);
      std::cout << std::endl;

      std::vector<char> solution1;
      std::vector<char> solution2;

      // Measure the time for MergeSort
      auto startMerge = std::chrono::high_resolution_clock::now();
      MergeSort<char> mergeSort;
      solution1 = mergeSort.solve(data);
      auto endMerge = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> mergeTime = endMerge - startMerge;

      // Measure the time for QuickSort
      auto startQuick = std::chrono::high_resolution_clock::now();
      QuickSort<char> quickSort;
      solution2 = quickSort.solve(data2);
      auto endQuick = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> quickTime = endQuick - startQuick;
      
      std::cout << "\x1B[31mSolved Vector 1:\x1B[0m ";
      printVector(solution1);
      std::cout << "\x1B[31mSolved Vector 2:\x1B[0m ";
      printVector(solution2);
      std::cout << std::endl;

      // Print times
      std::cout << "\x1B[31mMergeSort Time:\x1B[0m " << mergeTime.count() << " milliseconds for a vector size of \x1B[45m[" 
                << data.size() << "]\x1B[0m\n";
      std::cout << "\t" << mergeSort.recurrence() << std::endl;
      mergeSort.showMod();
      std::cout << "\x1B[31mQuickSort Time:\x1B[0m " << quickTime.count() << " milliseconds for a vector size of \x1B[45m[" 
                << data2.size() << "]\x1B[0m\n";
      std::cout << "\t" << quickSort.recurrence() << std::endl;
      quickSort.showMod();
    
    } 
    // Wait one second to genereate a new random vector
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nDo u want continue? [y/n]: ";
    std::cin >> c;
  }
}
