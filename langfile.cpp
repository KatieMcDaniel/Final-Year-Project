#include "soundpairTable.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream> 
#include <sstream>
#include <locale>
#include <codecvt>

using namespace std;

// class soundpairTable {


//  public:

//   soundpairTable();
//   soundpairTable(string table);
//   vector<soundpair> the_pairs;

//   bool shift(string src, string &trg);

//   void show();


// };

soundpairTable::soundpairTable() {}

soundpairTable::soundpairTable(string table_name) {
    // File pointer 
    fstream fin;

    fin.open(table_name, ios::in);

    if (fin.is_open()) {

        // Read the Data from the file 
        // as String Vector 
        vector<string> row;
        string line, word, temp;


        getline(fin, line); // to skip header
        while (getline(fin, line)) { // read an entire row and store it in a string variable 'line' 
            row.clear();
            // used for breaking words 
            stringstream s(line);
            // read every column data of a row and store it in a string variable, 'word' 
            while (getline(s, word, '\t')) {
                // add all the column data of a row to a vector 
                row.push_back(word);
            }

            soundpair sp;
            // set parts of sp from row
            sp.firstLang = "PIE";
            sp.firstSound = row[0];
            sp.secondLang = row[1];
            sp.secondSound = row[2];

            // add sp to the_pairs
            the_pairs.push_back(sp);

        }

    }
    else { cout << "File didn't open." << endl; }

}


void soundpairTable::show() {


    for (int i = 0; i < the_pairs.size(); i++) {
        soundpair sp;
        sp = the_pairs[i];

        if (sp.firstLang != "PIE") {
            cout << sp.firstLang << '\t';
        }

        cout << sp.firstSound << '\t';
        cout << sp.secondLang << '\t';
        cout << sp.secondSound << '\n';

    }


}