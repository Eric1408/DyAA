#include <iostream>
#include <fstream>
#include <future>
#include <chrono>

#include "voraz.h"
#include "brutus.h"
#include "graph.h"


int main(int argc, char* argv[]) {
  std::ifstream file(argv[1]);
  Graph graph(file);  
  //graph.showGraph();

  Greedy greedy;
  std::promise<void> promise_greedy;
  std::future<void> future_greedy = promise_greedy.get_future();

  greedy.resolve(graph, std::move(future_greedy));

  promise_greedy.set_value();
  greedy.PrintPath();
  std::cout << "Execution time (Greedy): " << greedy.getTime().count() << "ms" << std::endl;
  std::cout << "MinVal (Greedy): " << greedy.GetMinVal() << std::endl;


  Brutus brutus;
  std::promise<void> promise_brutus;
  std::future<void> future_brutus = promise_brutus.get_future();

  brutus.resolve(graph, std::move(future_brutus));
  promise_brutus.set_value();
  brutus.PrintPath();
  std::cout << "Execution time (Brutus): " << brutus.getTime().count() << "ms" << std::endl;
  std::cout << "MinVal (Brutus): " << brutus.GetMinVal() << std::endl;

  return 0;
}
