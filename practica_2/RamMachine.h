#ifndef _RAMMACHINE_H_
#define _RAMMACHINE_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "OTape.h"
#include "ITape.h"
#include "Memory.h"
#include "Program.h"
#include "Instruction.h"

using namespace std;


class RamMachine {
  bool error_;
  unsigned pc_;
  ITape* inTape_;
  OTape* outTape_;
  Memory* memory_;
  Program* program_;

public:
  RamMachine(string in, string out, string program, int size); // Cinta de entrada, Cinta de salida, programa y tamaño de memoria
  ~RamMachine();

  void showMemory();
  void showProgram();
  void showInputTape();
  void runProgram(bool);
  void resetInTape(string);
  void resetOutTape(string);
  void resetProgram(string);
  void showActualState(Instruction*);
  void resetMachine(string,string,string);

  string getInputFileName();
  string getOutputFileName();
  string getProgramFileName();

  void saveToOutputTape();

  int nInstruction;

private:
  void jumpManager(Instruction*);
};

#endif
