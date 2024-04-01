#pragma once


class Task {
 private:
  unsigned id_;
  unsigned time_;
 public:
  Task(unsigned id, unsigned time) : id_(id), time_(time) {}
  unsigned getId() const { return id_; }
  unsigned getTime() const { return time_; }
};
