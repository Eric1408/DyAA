/** Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 3do
 * @category Diseño y Analisis de Algoritmos
 * @file main.cc
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @brief This is a calculator matrix products, it's developed with
 *        SOLID Principles.
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
*/

#include <iostream>
#include <fstream>
#include <chrono>
#include "Calculator.h"

int main() {
  std::ofstream outputFile("resultados.txt"); // Abre el archivo para escribir resultados
  
  // Definir tamaños específicos para las matrices
  int sizes[10][2] = {{50, 40}, {50, 50}, {50, 60}, {50, 70}, {50, 80}, 
                     {50, 11}, {50, 22}, {50, 33}, {50, 44}, {50, 99}};
  // Matriz pivote para que la multiplicación sea compatible
  Matrix pivot(50, 50);  // Ajusta las dimensiones de pivot según tus necesidades

  // Crear cinco matrices con tamaños específicos
  Matrix matrices[10];
  for (int i = 0; i < 10; ++i) {
    int rows = sizes[i][0];
    int cols = sizes[i][1];
    matrices[i] = Matrix(rows, cols);
  }

  ColWise colWise;
  RoWise rowWise;

  for (int j = 0; j < 10; ++j) {
    // Realizar multiplicación por columnas
    auto startCol = std::chrono::high_resolution_clock::now();
    Matrix resultCol = colWise.multiply(pivot, matrices[j]);
    auto endCol = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationCol = endCol - startCol;
    outputFile << resultCol.getRows() * resultCol.getCols() << " " << durationCol.count();

    // Realizar multiplicación por filas
    auto startRow = std::chrono::high_resolution_clock::now();
    Matrix resultRow = rowWise.multiply(pivot, matrices[j]);
    auto endRow = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRow = endRow - startRow;
    outputFile << " " << durationRow.count() << std::endl;
  }

  outputFile.close(); // Cierra el archivo

  return 0;
}
