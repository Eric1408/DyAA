#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

typedef std::vector<std::vector<int>> IntMatrix;

struct Matrix {
  IntMatrix data;

  // Constructor
  Matrix() : data{} {}
  Matrix(int, int, int, int);
  Matrix(int, int, int);
  Matrix(int, int);

  void print() const;
  int getRows() { return data.size(); }
  int getCols() { return data[0].size(); }
};

// Strategy Interface
class Calculator {
 public:
  /**
   * @def virtual pure
   * @brief Cuando declaramos un método virtual puro y lo igualamos a 0,
   * estamos indicando que la clase que contiene este método es una clase abstracta y que no se puede crear instancias de ella directamente. 
   * Las clases abstractas son aquellas que tienen al menos un método virtual puro y no proporcionan una implementación para ese método.
   */
  virtual Matrix multiply(const Matrix&, const Matrix&) const = 0; 
  /**
   * @def virtual destructor equals to 0
   * @brief Cuando una clase tiene al menos un método virtual, se recomienda proporcionar
   * un destructor virtual. Esto es especialmente importante cuando se trata de clases base que se utilizan en la herencia. 
   * El destructor virtual permite que se llame correctamente al destructor 
   * de las clases derivadas cuando se eliminan objetos a través de un puntero a la clase base.
  */
  virtual ~Calculator() = default;
};

class ColWise : public Calculator {
 public:
 /**
  * @def override
  * @brief El uso de la palabra clave override en C++ es importante para indicar explícitamente que una función 
  * en una clase derivada está destinada a sobrescribir una función virtual de la clase base. 
  * Esto ayuda al compilador a verificar que la función en la clase derivada tiene 
  * la misma firma que la función virtual en la clase base, evitando errores sutiles.
 */
  Matrix multiply(const Matrix&, const Matrix&) const override;
};

class RoWise : public Calculator {
 public:
  Matrix multiply(const Matrix&, const Matrix&) const override;
};
