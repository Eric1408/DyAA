#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>    // std::reverse
#include <sstream>
#include <exception>
#include <regex>

#include "Instruction.h"
#include "Tag.h"

using namespace std;


class Program {
private:
  vector<Instruction*> instructions_;
  vector<Tag*> tags_;
  string fileName_;
  
  void load(string);
  void setTags(string);
  bool existsTag(string);
  string readFile(string);
  void parseInstructions(string);
  string getTagFromString(string);

public:
  Program(string);
  ~Program();

  void show();
  void reset(string);
  string getFileName ();
  bool reachHalt(unsigned);
  int getLineByTag(string);
  Instruction* getInstruction(unsigned line);
  
};



#endif
