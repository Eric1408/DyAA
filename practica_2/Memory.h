#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <vector>
#include <string>

typedef unsigned t_register; 
typedef int t_data;

using namespace std;


class Memory{
  vector<t_data> registers_;
public:
  Memory(int);
  ~Memory();

  void show();
  void clear();
  void reset();
  t_data read(t_register);
  void write(t_data,t_register);
};

#endif
