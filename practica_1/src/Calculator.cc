#include "Calculator.h"

Matrix::Matrix(int minRows, int maxRows, int minCols, int maxCols) {
  
  // Generamos dimensiones aleatorias dentro del rango especificado
  int rows = std::rand() % (maxRows - minRows + 1) + minRows;
  int cols = std::rand() % (maxCols - minCols + 1) + minCols;
  
  // Establecemos las dimensiones de la matriz
  data.resize(rows, std::vector<int>(cols, 0));
  
  // Llenamos la matriz con valores aleatorios
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      data[i][j] = std::rand() % 100; // Números aleatorios entre 0 y 99
    }
  }

}

Matrix::Matrix (int nRows, int nCols, int element) {
  
  data.resize(nRows, std::vector<int>(nCols,0));

  for (int i = 0; i < nRows; ++i) {
    for (int j = 0; j < nCols; ++j) {
      data[i][j] = element; 
    }
  }
}


Matrix::Matrix (int nRows, int nCols) {
  
  data.resize(nRows, std::vector<int>(nCols,0));

  // Llenamos la matriz con valores aleatorios
  for (int i = 0; i < nRows; ++i) {
    for (int j = 0; j < nCols; ++j) {
      data[i][j] = std::rand() % 100; // Números aleatorios entre 0 y 99
    }
  }
}

void Matrix::print() const {
  for (const auto& row : data) {
    for (int element : row) {
      std::cout << element << ' '; 
    }
    std::cout << std::endl;
  }
}

// Implementación de la función multiply para ColWise
Matrix RoWise::multiply(const Matrix& matrix1, const Matrix& matrix2) const {
  const IntMatrix& data1 = matrix1.data;
  const IntMatrix& data2 = matrix2.data;

  if (data1.empty() || data2.empty() || data1[0].empty() || data2[0].empty() || data1[0].size() != data2.size()) {
    // Matrices vacías o tamaños incompatibles
    // Puedes manejar esto según tus requisitos específicos
    throw std::invalid_argument("Matrices no compatibles para la multiplicación");
  }

  int m = data1.size();    // Número de filas de la primera matriz
  int n = data2[0].size(); // Número de columnas de la segunda matriz
  int p = data2.size();    // Número de columnas de la primera matriz (debe ser igual al número de filas de la segunda matriz)

  // Crear una matriz resultante con todas las entradas inicializadas a 0
  Matrix result(m, n, 0);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < p; ++k) {
        result.data[i][j] += data1[i][k] * data2[k][j];
      }
    }
  }

  return result;
}

// Implementación de la función multiply para RoWise
Matrix ColWise::multiply(const Matrix& matrix1, const Matrix& matrix2) const {
  const IntMatrix& data1 = matrix1.data;
  const IntMatrix& data2 = matrix2.data;

  if (data1.empty() || data2.empty() || data1[0].empty() || data2[0].empty() || data1[0].size() != data2.size()) {
    // Matrices vacías o tamaños incompatibles
    // Puedes manejar esto según tus requisitos específicos
    throw std::invalid_argument("Matrices no compatibles para la multiplicación");
  }

  int m = data1.size();    // Número de filas de la primera matriz
  int n = data2[0].size(); // Número de columnas de la segunda matriz
  int p = data1[0].size(); // Número de columnas de la primera matriz (debe ser igual al número de filas de la segunda matriz)

  // Crear una matriz resultante con todas las entradas inicializadas a 0
  Matrix result(m, n, 0);

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      for (int k = 0; k < p; ++k) {
        result.data[i][j] += data1[i][k] * data2[k][j];
      }
    }
  }

  return result;
}
