#include "problem.h"

Problem::Problem(std::ifstream& file) {
  // Dummy var allow to us skip the frist string of each line
  std::string dummy;

  // Line 1
  file >> dummy >> taskNumber_;
  // Line 2
  file >> dummy >> machines_;
  // Line 3
  file >> dummy;

  setupTime_.resize(taskNumber_+1, std::vector<unsigned>(taskNumber_+1));
  taskTime_.resize(taskNumber_);

  for (unsigned i = 0; i < taskNumber_; ++i) {
    file >> taskTime_[i];
  }
  getline(file, dummy);
  
  // Line 4
  getline(file, dummy);
  
  // Line 5
  for (unsigned i = 0; i <= taskNumber_; ++i) {
    for (unsigned j = 0; j <= taskNumber_; ++j) {
      file >> setupTime_[i][j];
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Problem& problem) {
  os << "Task number: " << problem.taskNumber_ << std::endl;
  os << "Machines: " << problem.machines_ << std::endl;
  os << "Task time: ";
  for (unsigned i = 0; i < problem.taskNumber_; ++i) {
    os << problem.taskTime_[i] << " ";
  }
  os << std::endl;

  os << "Setup time: " << std::endl;
  for (unsigned i = 0; i <= problem.taskNumber_; ++i) {
    for (unsigned j = 0; j <= problem.taskNumber_; ++j) {
      os << problem.setupTime_[i][j] << " ";
    }
    os << std::endl;
  }

  return os;
}
