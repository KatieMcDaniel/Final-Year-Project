
#include "soundpairTable.h"

using namespace std;


soundpairTable::soundpairTable() {}

soundpairTable::soundpairTable(string table_name, int type) {
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
            //varible type used so the code can easily be changed from using orth to IPA
            sp.secondSound = cvt.from_bytes(row[type]);

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
    sort();
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
bool soundpairTable::find(u32string firstSound, u32string& secondSound, int& pos) {

    
    for (int i = pos; i < the_pairs.size(); i++) {
        soundpair sp;
        sp = the_pairs[i];

        if (sp.firstSound == firstSound) {
            secondSound = sp.secondSound;
            return true;
        }
    }

    return false;
}

void soundpairTable::sort()
{
    for (int i = 1; i < the_pairs.size(); i++)
    {
        soundpair temp;
         temp = the_pairs[i];
        // Insert s[j] at its correct position
        int j = i - 1;
        while (j >= 0 && temp.firstSound.length() > the_pairs[j].firstSound.length())
        {
            the_pairs[j+1] = the_pairs[j];
            j--;
        }
        the_pairs[j + 1] = temp;
    }
}

bool soundpairTable::longest_prefix(u32string input, int start, int& index, int& len, u32string& one, u32string& two) {

    int max_len = 0;
    bool whether_found = false;
    u32string sym;
    int sym_len;

    for (int i = 0; i < the_pairs.size(); i++) {
        sym = the_pairs[i].firstSound;
        sym_len = sym.size();
        if (sym_len <= max_len) { // already have longer match
            continue;
        }

        if ((input.size() - start) < sym_len) { // not enough remains for sym to occur in input here
            continue;
        }

        u32string chunk_to_compare;
        chunk_to_compare = input.substr(start, sym_len);
        if (chunk_to_compare == sym) {
            max_len = sym_len;
            index = i;
            len = max_len;
            one = the_pairs[i].firstSound;
            two = the_pairs[i].secondSound;
            whether_found = true;
        }
    }

    return whether_found;

}
