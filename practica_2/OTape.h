#ifndef _OTAPE_H_
#define _OTAPE_H_

#include "Tape.h"
#include <string>

using namespace std;
// Output tape
class OTape : public Tape{
public:
  OTape(string);
  ~OTape();
  void write(int);
  void saveToFile();
  void reset(string);
  void reset();
};

#endif
