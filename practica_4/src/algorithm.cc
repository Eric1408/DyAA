#include "algorithm.h"

void DivideAndConquer::solve(std::vector<int>& data) {
  if (small(data)) {
    solveSmall(data);
  } else {
    std::vector<int> left, right;
    divide(data, left, right);

    solve(left);
    solve(right);

    combine(data, left, right);
  }
}
