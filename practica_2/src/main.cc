/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Curso: 3
 * 
 * @category Diseño y Análisis de Datos
 * @file main.cc
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @brief
 * 
 * @date 01-02-2024
 * 
 * @copyright Copyright (c) 2024
*/

#include <iostream>
#include "../include/memory.h"

int main() {
  RegisterMemory m1;
  std::cout << m1.read(0) << std::endl;

  return 0;
}
