#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>

#include "../include/menu.h"

#include "DaC.cc"
#include "merge.cc"
#include "hanoi.cc"
#include "quick.cc"
#include "binary.cc"

const int SIZE = 6;

/**
 * Generates a random vector of a specified type.
 *
 * @tparam T The type of the elements in the vector.
 * @return The randomly generated vector.
 */
template <typename T>
std::vector<T> randomVector() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  int size = std::rand() % SIZE + 1;
  std::vector<T> data(SIZE);
  
  for (auto& element : data) {
    if constexpr (std::is_same<T, int>::value) {
      element = std::rand() % SIZE;  // For integral types
    } else if constexpr (std::is_same<T, float>::value) {
      element = static_cast<T>(std::rand()) / static_cast<T>(SIZE);  // For floating-point types
    } else if constexpr (std::is_same<T, char>::value) {
      element = static_cast<char>('A' + std::rand() % 26);  // For char type (uppercase letters)
    }
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


template <typename T>
void runSortingExperiment(int algorithm) {
  std::vector<T> data = randomVector<T>();
  std::vector<T> solution;
  

  if (algorithm == 1) {
    std::cout << "\x1B[31mRandom Vector 1:\x1B[0m ";
    printVector(data);
    std::cout << std::endl;

    // Mide el tiempo para MergeSort
    auto startMerge = std::chrono::high_resolution_clock::now();
    MergeSort<T> mergeSort;
    solution = mergeSort.solve(data);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mergeTime = endMerge - startMerge;

    // Imprime los vectores ordenados
    std::cout << "\x1B[31mSolved Vector:\x1B[0m ";
    printVector(solution);

    // Imprime los tiempos
    std::cout << "\x1B[31mMergeSort Time:\x1B[0m " << mergeTime.count() << " milliseconds for a vector size of \x1B[45m["
              << data.size() << "]\x1B[0m\n";
    std::cout << "\t" << mergeSort.recurrence() << std::endl;
    mergeSort.showMod();
  } else if (algorithm == 2) {
    std::cout << "\x1B[31mRandom Vector:\x1B[0m ";
    printVector(data);
    std::cout << std::endl;

    // Mide el tiempo para QuickSort
    auto startQuick = std::chrono::high_resolution_clock::now();
    QuickSort<T> quickSort;
    solution = quickSort.solve(data);
    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> quickTime = endQuick - startQuick;

    // Imprime los vectores ordenados
    std::cout << "\x1B[31mSolved Vector 2:\x1B[0m ";
    printVector(solution);
    std::cout << std::endl;

    // Imprime los tiempos
    std::cout << "\x1B[31mQuickSort Time:\x1B[0m " << quickTime.count() << " milliseconds for a vector size of \x1B[45m["
              << solution.size() << "]\x1B[0m\n";
    std::cout << "\t" << quickSort.recurrence() << std::endl;
    quickSort.showMod();
  } else if (algorithm == 3) {
    // Binary
    std::cout << "\x1B[31mRandom Vector:\x1B[0m ";
    printVector(data);
    QuickSort<T> quickSort;
    solution = quickSort.solve(data);
    
  } else if (algorithm == 4) {
    int n;
    std::cout << "Choose the number of disks: ";
    std::cin >> n;

    // Mide el tiempo para Hanoi
    auto startHanoi = std::chrono::high_resolution_clock::now();
    Hanoi<T> hanoi;
    DivideAndConquer<T>::Hanoi(n, 'A', 'C', 'B');
    auto endHanoi = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> hanoiTime = endHanoi - startHanoi;

    // Imprime los tiempos
    std::cout << "\x1B[31mHanoi Time:\x1B[0m " << hanoiTime.count() << " milliseconds for \x1B[45m["
              << n << "]\x1B[0m disks\n";
    std::cout << "\t" << hanoi.recurrence() << std::endl;
  }
}

void menu() {
  char c = 'y';
  while (c == 'y') {
    system("clear");
    
    // Selección del tipo de datos
    int algorithm;
    std::cout << "Choose algorithm [MergeSort[1], QuickSort[2], BinarySearch[3], HanoiProblem[4]]\n";
    std::cin >> algorithm;
    
    std::string type{"hanoi"};
    if (algorithm == 1 || algorithm == 2 || algorithm == 3) {
      std::cout << "Choose a data type [int, char, float]\n";
      std::cin >> type;
  
    }
    
    if (type == "int") {
      runSortingExperiment<int>(algorithm);
    } else if (type == "float") {
      runSortingExperiment<float>(algorithm);
    } else if (type == "char") {
      runSortingExperiment<char>(algorithm);
    } else if (type == "hanoi") {
      runSortingExperiment<int>(algorithm);
    } else {
      std::cout << "Invalid data type\n";
    }

    // Espera un segundo para generar un nuevo vector aleatorio
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nDo you want to continue? [y/n]: ";
    std::cin >> c;
  }
}
