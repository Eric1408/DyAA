#pragma once

#include <vector>

#include "task.h"

class Machine {
 private:
  std::vector<Task> tasks_;
 public:
  Machine();
  const std::vector<Task>& getTasks() const { return tasks_; }
  void addTask(const Task& task) { tasks_.push_back(task);}
};
