#include "soundpairTable.h"


langfile::langfile(string first, string second)
    : firstLang(first), secondLang(second), firstSound(), secondSound(), firstPlace(0), secondPlace(0)
{}

//opens the files containg the sound evolution tables and uses them to find the relavent sound pair 
void langfile::getLetter(int position) {

    string letter;

    // File pointer 
    fstream fonein;

    if (firstLang == "Ger") { fonein.open("Tables/sound_evol_pie_ger.csv", ios::in); }
    if (firstLang == "Grk") { fonein.open("Tables/sound_evol_pie_grk.csv", ios::in); }
    if (firstLang == "Lat") { fonein.open("Tables/sound_evol_pie_grk.csv", ios::in); }

    if (fonein.is_open()) {

        // Read the Data from the file 
        // as String Vector 
        vector<string> row;
        string line, word, temp;
        int counter = 0;
        u32string s;

        while (fonein >> temp) {
            // make utf32 from utf8
            s = cvt.from_bytes(temp);
            int len = s.length();
            row.clear();
            // read an entire row and store it in a string variable 'line' 
            getline(fonein, line);
            // used for breaking words 
            stringstream s(line);
            // read every column data of a row and store it in a string variable, 'word' 
            while (getline(s, word, '\t')) {
                // add all the column data of a row to a vector 
                row.push_back(word);
            }
            counter++;
            if (counter == position) {
                letter = row[0];
                firstSound = cvt.from_bytes(row[2]);
                break;
            }
            
        }
    }

    else { cout << "File didn't open." << endl; }

    fstream ftwoin;

    if (secondLang == "Ger") { ftwoin.open("Tables/sound_evol_pie_ger.csv", ios::in); }
    if (secondLang == "Grk") { ftwoin.open("Tables/sound_evol_pie_grk.csv", ios::in); }
    if (secondLang == "Lat") { ftwoin.open("Tables/sound_evol_pie_grk.csv", ios::in); }

    if (ftwoin.is_open()) {

        vector<string> row;
        string line, word, temp;
        u32string s;
        while (ftwoin >> temp) {
            s = cvt.from_bytes(temp);
            int len = s.length();
            row.clear();
            getline(ftwoin, line);
            stringstream s(line);

            while (getline(s, word, '\t')) {
                row.push_back(word);
            }
       
            if (row[0] == letter) {
                len = row[2].length();
                /* if (len > 1) {
                 revisit what must be done if there is a few letters in a row. 
                 Read it and if a ";" appears then go in for a second time.
                 Do you go in for a second time? Email and ask for an explaination before doing anything else 
                } */
                secondSound = cvt.from_bytes(row[2]); 
                break;
            }
        }
    }

    else { cout << "File didn't open." << endl; }

    return;
}

/*

    OK HERE WE GO!!!

    READ THE THING, FIND A PIE LETTER
    SET UP NEXT LOOP AND READ THE NEXT LANGAUGE FILE FOR A PIE LETTER
    THEN READ OF ; OR / OR WHATEVER AND PUT IN SOME SORT OF MARKER TO LET THAT BE KNOWN. 
    MAYBE DO SOME SORT OF COMPARISION TO PREVIOUSLT CHECKED LETTERS
    THEN AT THE END CHECK VERUS SOME SORT OF TEST THINGY

*/