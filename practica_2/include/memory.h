// #pragma once serves the same purpose as include guards, but with several advantages, including less code, avoidance of name clashes, 
// and sometimes improvement in compilation speed.
#pragma once

#include <stdexcept>
#include <iostream>
#include <vector>

class Memory {
 public:
  virtual int read(int address) const = 0;
  virtual void write(int address, int data) = 0; 

  virtual ~Memory() = default;

 protected:
  bool checkAddr(int) const;
  std::vector<int>& getData();
  const std::vector<int>& getData() const;

 private:
  std::vector<int> data_;
};

class DataMemory : public Memory {
 public:
  int read(int) const override;
  void write(int, int) override;

};

class RegisterMemory : public Memory {
 public:
  RegisterMemory();
  
  int read(int) const override;
  void write(int, int) override;
};
