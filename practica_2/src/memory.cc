#include "../include/memory.h"

bool Memory::checkAddr(int address) const {
  if (address < 0 || address >= static_cast<int>(data_.size())) {
    return false;
  }

  return true;
}

std::vector<int>& Memory::getData() {
  return data_;
}

const std::vector<int>& Memory::getData() const {
  return data_;
}

int DataMemory::read(int address) const {
  if(!checkAddr(address)) {
    throw std::out_of_range("Invalid memory address!");
  }

  return getData()[address];
}

void DataMemory::write(int address, int data) {
  if(!checkAddr(address)) {
    throw std::out_of_range("Invalid memory address!");
  }

  getData()[address] = data;
}

RegisterMemory::RegisterMemory() {
  
}

int RegisterMemory::read(int address) const {
  if (!checkAddr(address)) {
    throw std::out_of_range("Invalid memory address!");
  }

  return getData()[address];
}

void RegisterMemory::write(int address, int data) {
  throw std::invalid_argument("Write operation inhabilitate for ResgisterMemory object.");
}
