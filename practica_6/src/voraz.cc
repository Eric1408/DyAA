#include "voraz.h"

void Greedy::resolve(const Graph& graph, std::future<void> future) {
  const int numNodes = graph.size();
  std::vector<bool> visited(numNodes, false);
  std::vector<int> path;
  int currentNode = 0; // Empezamos desde el nodo 0
  int totalCost = 0;

  visited[currentNode] = true;
  path.push_back(currentNode);

  while (path.size() < numNodes) {
    int nextNode = -1;
    
    if (future.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready){
      excesive_ = true;
      return;
    }

    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
      if (!visited[neighbor] && graph[currentNode][neighbor] > 0 && graph[currentNode][neighbor] < minVal_) {
        minVal_ = graph[currentNode][neighbor];
        nextNode = neighbor;
        //totalCost += minVal_;
        std::cout << "CurrentNode: " << char(currentNode + 'A') << " neighbor: " << char(neighbor+'A') << " minVal: " << minVal_ << " graph[currentNode][neighbor]: " << graph[currentNode][neighbor] << std::endl;
      }
    }

    if (nextNode == -1) {
      // Si no encontramos un nodo vecino no visitado, regresamos al nodo inicial
      nextNode = 0;
    }
    std::cout << "minVal: " << minVal_ << std::endl;
    visited[nextNode] = true;
    path.push_back(nextNode);
    currentNode = nextNode;
    totalCost += minVal_;
  }

  // Agregamos el nodo inicial al final del recorrido
  //path.push_back(0);
  minVal_ = totalCost;
  path_ = path;

  return;
}

/*
void Greedy::resolve(const Graph& graph, std::future<void> futuro) {
  auto start_time = std::chrono::steady_clock::now(); // Momento de inicio

  std::vector<bool> visited(graph.size() - 1, false);
  visited[0] = true;
  int currentNode = 0;
  int result = 0;
  path_.push_back(currentNode);
  
  for (int i = 0; i < graph.size() - 1; i++) {
    if (futuro.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready){
      excesive_ = true;
      return;
    }

    int min = 9999;
    int nextNode = 0;
    for (int j = 0; j < graph.size(); j++) {
      if (graph[currentNode][j] < min && !visited[j] && graph[currentNode][j] != 0) {
        //std::cout << "CurrentNode: " << char(currentNode + 'A') << " j: " << char(j+'A') << " min: " << min << " graph[currentNode][j]: " << graph[currentNode][j] << std::endl;
        min = graph[currentNode][j];
        //std::cout << min << std::endl;
        nextNode = j;
      }
    }
    visited[nextNode] = true;
    result += min;
    currentNode = nextNode;
    path_.push_back(currentNode);
  }
  result += graph[currentNode][0];
  //path_.push_back(0);
  minVal_ = result;

  auto end_time = std::chrono::steady_clock::now(); // Momento de finalización
  executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); // Guardar el tiempo de ejecución

  return;
}
*/