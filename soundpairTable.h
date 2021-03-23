#if !defined SOUNDPAIR_TABLE
#define SOUNDPAIR_TABLE

#include "soundpair.h"
#include <string>
#include <vector>
using namespace std;

class soundpairTable {


 public:
  
  soundpairTable();
  soundpairTable(string table);
  vector<soundpair> the_pairs;
  
  bool shift(string src, string &trg);

  void show();


};

#endif


