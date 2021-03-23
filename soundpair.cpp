#include "soundpair.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream> 
#include <sstream>
#include <locale>
#include <codecvt>

using namespace std;

wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

//soundpair constructer 
soundpair::soundpair()
    :firstLang(), secondLang(), firstSound(), secondSound(), firstPlace(0), secondPlace(0), match()
{}

//sets the sound pair params for when its trying out multiple sound shifts 
//yeah should defos be a seperate class for doing this tbh...
void soundpair::setSoundPair(int position, string first, string second) {
    firstLang = first;
    secondLang = second;
    getLetter(firstLang, position, firstSound);
    getLetter(secondLang, position, secondSound);
}

//sets the soundpair params when its known that the sound shifft matches up 
void soundpair::setSoundPair(string firstS, string secondS, int firstP, int secondP) {
     firstSound = firstS;
     secondSound = secondS;
     firstPlace = firstP;
     secondPlace = secondP;
     match = true;
}

//opens the files containg the sound evolution tables and uses them to find the relavent sound pair 
void soundpair::getLetter(string lang, int position, string& letter) {
    // File pointer 
    fstream fin;
   
    if (lang == "Ger") { fin.open("Tables/sound_evol_pie_ger.csv", ios::in); }
    if (lang == "Grk") { fin.open("Tables/sound_evol_pie_grk.csv", ios::in); }
    if (lang == "Lat") { fin.open("Tables/sound_evol_pie_grk.csv", ios::in); }
    
    if (fin.is_open()) {
  
        // Read the Data from the file 
        // as String Vector 
        vector<string> row;
        string line, word, temp;
        int counter = 0;
        u32string s;
        while (fin >> temp) {
            // make utf32 from utf8
            s = cvt.from_bytes(temp);
            int len = s.length();
            row.clear();
            // read an entire row and store it in a string variable 'line' 
            getline(fin, line);
            // used for breaking words 
            stringstream s(line);
            // read every column data of a row and store it in a string variable, 'word' 
            while (getline(s, word, '\t')) {
                // add all the column data of a row to a vector 
                row.push_back(word);
            }
            counter++;
            if (counter == position) {
                letter = row[2];
                return;
            }
        }
    }

    else { cout << "File didn't open." << endl; }
   
    return;
};
