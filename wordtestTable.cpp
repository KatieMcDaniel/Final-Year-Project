#include "wordtestTable.h"
#include "wordtest.h"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>
#include <vector>

using namespace std;

wordtestTable::wordtestTable() {}

wordtestTable::wordtestTable(int type){

    string words = { "Tables/cognates_table.csv" };
    fstream fin;

    fin.open(words, ios::in);

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
   
            wordtest wt;
            // add to whichever pair group is the correct one for the language being used 

            if (row[2] == "OE") {
                // set parts of wt from row
                wt.firstLang = "PIE";
                wt.firstWord = row[1];
                wt.secondLang = row[2];
                //varible type used so the code can easily be changed from using orth to IPA
                wt.secondWord = row[type];

                // add wt to oe_pairs
                oe_pairs.push_back(wt);
            }

            if (row[2] == "La") {
                // set parts of wt from row
                wt.firstLang = "PIE";
                wt.firstWord = row[1];
                wt.secondLang = row[2];
                //varible type used so the code can easily be changed from using orth to IPA
                wt.secondWord = row[type];

                // add wt to la_pairs
                la_pairs.push_back(wt);
            }

            if (row[2] == "AGr") {
                wordtest wt;
                // set parts of wt from row
                wt.firstLang = "PIE";
                wt.firstWord = row[1];
                wt.secondLang = row[2];
                //varible type used so the code can easily be changed from using orth to IPA
                wt.secondWord = row[type];

                // add wt to agr_pairs
                agr_pairs.push_back(wt);

            }
        }
  
    }

    else { cout << "File didn't open." << endl; }

}

void wordtestTable::show() {

    for (int i = 0; i < the_pairs.size(); i++) {
        wordtest wt;
        wt = the_pairs[i];

        cout << wt.firstLang << '\t';
        cout <<wt.firstWord << '\t';
        cout << wt.secondLang << '\t';
        cout << wt.secondWord << '\n';

    }
}

void wordtestTable::organise(string firstLang, string secondLang) {

    if (firstLang == "Ger") { first_pairs = oe_pairs; }
    if (firstLang == "Lat") { first_pairs = la_pairs; }
    if (firstLang == "Grk") { first_pairs = agr_pairs; }

    if (secondLang == "Ger") { second_pairs = oe_pairs; }
    if (secondLang == "Lat") { second_pairs = la_pairs; }
    if (secondLang == "Grk") { second_pairs = agr_pairs; }


 
    //Get line from the first table
    for (int i = 0; i < first_pairs.size(); i++) {
        //go through lines in the second table
        for (int j = 0; j < second_pairs.size(); j++) {
            wordtest wt;
            // Check that the pairs both share the same PIE origin
            if (first_pairs[i].firstWord == second_pairs[j].firstWord) {
                //Assign values for the new table 
                wt.firstLang = first_pairs[i].secondLang;
                wt.firstWord = first_pairs[i].secondWord;
                wt.secondLang = second_pairs[j].secondLang;
                wt.secondWord = second_pairs[j].secondWord;
                the_pairs.push_back(wt);
            }
        }
    } 
}
