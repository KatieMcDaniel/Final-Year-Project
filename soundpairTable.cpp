#include "soundpairTable.h"

using namespace std;


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
            sp.firstSound = cvt.from_bytes(row[0]);
            sp.secondLang = row[1];
            sp.secondSound = cvt.from_bytes(row[2]);

            // add sp to the_pairs
            the_pairs.push_back(sp);

        }

    }
    else { cout << "File didn't open." << endl; }

}

soundpairTable::soundpairTable(vector<soundpair> first_pairs, vector<soundpair> second_pairs) {
   
    //Get line from the first table
    for (int i = 0; i < first_pairs.size(); i++) {
        //go through lines in the second table
        for (int j = 0; j < second_pairs.size(); j++) {
            soundpair sp;
            // Check that the pairs both share the same PIE origin
            if (first_pairs[i].firstSound == second_pairs[j].firstSound) {
                //Assign values for the new table 
                sp.firstLang = first_pairs[i].secondLang;
                sp.firstSound = first_pairs[i].secondSound;
                sp.secondLang = second_pairs[j].secondLang;
                sp.secondSound = second_pairs[j].secondSound;
                the_pairs.push_back(sp);
            }
   
        }

    }
}


//Prints out tables 
void soundpairTable::show() {

    for (int i = 0; i < the_pairs.size(); i++) {
        soundpair sp;
        sp = the_pairs[i];

        if (sp.firstLang != "PIE") {
            cout << sp.firstLang << '\t';
        }

        cout << cvt.to_bytes(sp.firstSound) << '\t';
        cout << sp.secondLang << '\t';
        cout << cvt.to_bytes(sp.secondSound) << '\n';

    }
}

//looks to see if a letter is found in a table
bool soundpairTable::find(u32string firstSound, u32string& secondSound) {

    for (int i = 0; i < the_pairs.size(); i++) {
        soundpair sp;
        sp = the_pairs[i];

        if (sp.firstSound == firstSound) {
            secondSound = sp.secondSound;
            return true; 
        }  
    }

    return false;
}