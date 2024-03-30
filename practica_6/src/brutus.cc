#include "brutus.h"

/*
int Brutus::calculateCost(const Graph& grafo, std::vector<int> path) {
  int cost = 0;
  for (int i = 0; i < path.size() - 1; i++) {
    cost += grafo[path[i]][path[i + 1]];
  }
  cost += grafo[path[path.size() - 1]][path[0]];
  return cost;
}

/**
 * @brief Resuelve el problema del viajante de comercio mediante fuerza bruta
 * @param grafo Grafo sobre el que se va a resolver el problema
 * @param futuro Objeto que indica si el algoritmo debe parar
 * @return Coste del camino obtenido

void Brutus::resolve(const Graph& grafo, std::future<void> futuro) {
  std::vector<int> path(grafo.size()-1);
  for (int i = 0; i < path.size(); i++) {
    path[i] = i;
  }
  int minCost = 999999;
  std::vector<int> minPath;
  do {
    if (futuro.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready) {
      excesive_ = true;
      path_ = path;
      return;
    }
    int currentCost = calculateCost(grafo, path);
    std::cout << "Current cost: " << currentCost << std::endl;
    if (currentCost < minCost) {
      minCost = currentCost;
      minPath = path;
    }
  } while (std::next_permutation(path.begin(), path.end()));

  path_ = minPath;
  minVal_ = minCost;

  return;
}
*/

/**
 * Calculates the cost of a given path in a graph.
 * 
 * @param path The path represented as a vector of integers.
 * @param graph The graph object representing the connections between nodes.
 * @return The total cost of the path.
 */
int Brutus::calculateCost(const std::vector<int>& path, const Graph& graph) {
  int total = 0;
  for (int i = 0; i < path.size() - 1; ++i) {
    int from = path[i];
    int to = path[i + 1];
    int distance = graph[from][to];
    if (distance == 0) {
      return INF;
    }
    total += distance;
  }
  
  return total;
}

/**
 * Resolves the graph using the Brutus algorithm.
 * 
 * @param graph The graph to be resolved.
 * @param future A future object used for checking if the algorithm should be interrupted.
 */
void Brutus::resolve(const Graph& graph, std::future<void> future) {
  int numCities = graph.size();
  std::vector<int> bestPath;

  std::vector<int> path(numCities);
  for (int i = 0; i < numCities; ++i) {
    path[i] = i;
  }
  do {
    if (future.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready) {
      excesive_ = true;
      path_ = path;
      return;
    }
    
    int currentDistance = calculateCost(path, graph);
    if (currentDistance < minVal_) {
      minVal_ = currentDistance;
      bestPath = path;
    }
  } while (std::next_permutation(path.begin() + 1, path.end())); // Generar todas las permutaciones posibles
  path_ = bestPath;

  return;
}
