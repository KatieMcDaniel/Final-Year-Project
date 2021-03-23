#include "soundpairTable.h"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>
#include <vector>

using namespace std;

int main() {

  vector<string> names = {"sound_evol_pie_ger.csv","sound_evol_pie_grk.csv"};

  soundpairTable t;
  for(int i=0; i < names.size();i++) {
    string fullname = "Tables/";
    fullname += names[i];
    cout << "testing: " << names[i] << endl << "*************" << endl;
    t = soundpairTable(fullname);
    t.show();

  }


}
