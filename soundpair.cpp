#include "soundpair.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream> 
#include <sstream>
using namespace std;

//soundpair constructer 
soundpair::soundpair(string first, string second)
    :firstLang(first), secondLang(second), firstSound(), secondSound(), firstPlace(0), secondPlace(0)
{}

void soundpair::setSoundPair(char first, char second) {
	firstSound = first;
	secondSound = second;
}

void soundpair::findSound(){
    // File pointer 
    fstream fin;
    // Open an existing file 
    fin.open("soundpairs.csv", ios::in);


    // Read the Data from the file 
    // as String Vector 
    vector<string> row;
    string line, word, temp;

    while (fin >> temp) {

        row.clear();
        // read an entire row and 
        // store it in a string variable 'line' 
        getline(fin, line);
        // used for breaking words 
        stringstream s(line);

        // read every column data of a row and 
        // store it in a string variable, 'word' 

        while (getline(s, word, ',')) {
            // add all the column data 
            // of a row to a vector 
            row.push_back(word);
        }

        if (row[1] == firstLang) {
            firstSound = row[2];
        }
    }
}