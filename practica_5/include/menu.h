#pragma once

#include <vector>

std::vector<int> randomIntVector();
std::vector<float> randomFloatVector();
std::vector<char> randomCharVector();

void menu();

template <typename T>
void printVector(const std::vector<T>&);