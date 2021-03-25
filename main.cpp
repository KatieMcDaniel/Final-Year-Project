#include <iostream>
#include <string>
#include "cogpair.h"
#include "soundpair.h"
#include "soundpairTable.h"
#include <vector>
#include <locale>
#include <codecvt>

using namespace std;

bool soundmatch(u32string word, u32string sound, int& place);

soundpairTable first_table;
soundpairTable second_table;
soundpairTable joint_table;

const string GRK = "Tables/sound_evol_pie_grk(rom_orth).csv";
const string GER = "Tables/sound_evol_pie_ger_no_alts.csv";
const string LAT = "Tables/sound_evol_pie_lat.csv";

wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

int main()
{
    u32string firstCog = cvt.from_bytes("darkia");
    u32string secondCog = cvt.from_bytes("heorta");

    string firstLang = "Grk";
    string secondLang = "Ger";

    // these lines create appropriate first_table and second_table
    if (firstLang == "Ger") { first_table = soundpairTable(GER); }
    if (firstLang == "Grk") { first_table = soundpairTable(GRK); }
    if (firstLang == "Lat") { first_table = soundpairTable(LAT); }

    if (secondLang == "Ger") { second_table = soundpairTable(GER); }
    if (secondLang == "Grk") { second_table = soundpairTable(GRK); }
    if (secondLang == "Lat") { second_table = soundpairTable(LAT); }

    first_table.show();
    second_table.show();

    //This creates a joint table with the cognates for both languages 
    joint_table = soundpairTable(first_table.the_pairs, second_table.the_pairs);

    joint_table.show();

    int l = firstCog.length();
    int place = 0;

    for (int i = 0; i <= l; i++) {
        //take a letter from the frist word
        u32string sOne(1, firstCog[i]);
        u32string sTwo;

        //find if the letter is in one of the tables
        bool search = joint_table.find(sOne, sTwo);

        if (search == true) {
            // See if the matching sound pair can be found in the second word
            bool match = soundmatch(secondCog, sTwo, place);
            //if match return matches
            if (match == true) {
                cout << "Match found with " << cvt.to_bytes(sOne) << " and " << cvt.to_bytes(sTwo) << endl;
            }
            // if not a match let the user know that one part of a part was found but the matching part was not
            if (match == false){
                cout << "Sound " << cvt.to_bytes(sOne) << " was found in " << cvt.to_bytes(firstCog)
                    << " but the matching sound " << cvt.to_bytes(sTwo) << " was not found in " << cvt.to_bytes(secondCog)
                    << endl;
            }
        }
    }

    return 0;
}

//check if the sound is found in the second word 
bool soundmatch(u32string word, u32string sound, int& place) {
    int l = word.length();

    for (int i = place; i <= l; i++) {
        u32string s(1, word[i]);
        if (s == sound) {
            place = i;
            return true;
        }
    }
    return false;
}