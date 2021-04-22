#include <iostream>
#include <string>
#include "cogpair.h"
#include "soundpair.h"
#include "soundpairTable.h"
#include "wordtestTable.h"
#include <vector>
#include <locale>
#include <codecvt>

using namespace std;

bool soundmatch(u32string word, u32string sound, int& place);

soundpairTable first_table;
soundpairTable second_table;
soundpairTable joint_table;

wordtestTable word_table;

const string GRK = "Tables/sound_evol_pie_grk(grk_orth).csv";
const string GER = "Tables/sound_evol_pie_ger.csv";
const string LAT = "Tables/sound_evol_pie_lat.csv";

wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

int main()
{
    //Type is used to chose if the soundpairs and words will be in orth or IPA. If the type is 3 it means orth, if the type is 4 it means IPA
    //The number indicates the row which will be read in the code. row[3] produces orth words, row[4] gives IPA words. 
    int type = 4;
    //create tables of words in different lanagauges 
    word_table = wordtestTable(type);

    //counts the number of correct matches 
    int corCount = 0;
    //counts the number of total matches checked
    int count = 0;
    //counts the numbers of matches that weren't correct but did contain part of a soundpair
    // a part refers to when one word contains part of a valid soundpair but the word it is being compared to does not
    int partCount = 0;
    //counts the number of matches that were correct and additionally contained part of a sound pair
    int partCorCount = 0;

    string firstLang = "Grk";
    string secondLang = "Lat";
  

    //organise the table previously created so that it contains the two langauges being checked in a way that easier to compare
    word_table.organise(firstLang, secondLang);

    // these lines create appropriate first_table and second_table
    //type - 1 gives the appropriate orth or IPA soundpair needed. May change to look a bit better.
    if (firstLang == "Ger") { first_table = soundpairTable(GER, type-1); }
    if (firstLang == "Grk") { first_table = soundpairTable(GRK, type-1); }
    if (firstLang == "Lat") { first_table = soundpairTable(LAT, type-1); }

    if (secondLang == "Ger") { second_table = soundpairTable(GER, type-1); }
    if (secondLang == "Grk") { second_table = soundpairTable(GRK, type-1); }
    if (secondLang == "Lat") { second_table = soundpairTable(LAT, type-1); }

    //This creates a joint table with the cognates for both languages 
    second_table.show();
    joint_table = soundpairTable(first_table.the_pairs, second_table.the_pairs);
    joint_table.show();

    //this for loop goes through each of the word pairs found in the word table
    for (int i = 0; i < word_table.the_pairs.size(); i++) {

        u32string firstCog = cvt.from_bytes(word_table.the_pairs[i].firstWord);
        u32string secondCog = cvt.from_bytes(word_table.the_pairs[i].secondWord);

        std::cout << "comparing " << word_table.the_pairs[i].firstWord << " and " << word_table.the_pairs[i].secondWord << endl;

        int l = firstCog.length();
        int place = 0;
        //checks if a match is correct
        bool correct = false;
        //checks if a part is correct 
        bool part = false;

        int start = 0;
        while (start < firstCog.size()) {
            bool found = false;
            int index = 0;
            int len = 0;
            int position = 0;
            u32string sOne, sTwo;
            found = joint_table.longest_prefix(firstCog, start, index, len, sOne, sTwo);
            if (found) {
                //while loop is added to ensure that for cases a letter has multiple possible soundpairs none of them are missed
                //e.g if d could match with d or f, it ensures the code does not stop looking at just d because it is what turns up first in the table
                //the position int is used to keep track of where in the table the code has searched so it does not get stuck in an endless loop repeating it self
                while (position != joint_table.the_pairs.size() - 1) {
                    // See if the matching sound pair can be found in the second word
                    bool match = soundmatch(secondCog, sTwo, place);
                    //if match return matches
                    if (match == true) {
                        //cout << "Match found with " << cvt.to_bytes(sOne) << " and " << cvt.to_bytes(sTwo) << endl;
                        correct = true;
                        position = joint_table.the_pairs.size() - 1;
                    }
                    // if not a match let the user know that one part of a part was found but the matching part was not
                    else {
                        part = true;
                        position++;
                        if (position == joint_table.the_pairs.size() - 1) {
                            std::cout << "Sound " << cvt.to_bytes(sOne) << " was found in " << cvt.to_bytes(firstCog)
                                << " but the matching sound " << cvt.to_bytes(sTwo) << " was not found in " << cvt.to_bytes(secondCog)
                                << endl;
                        }
                        bool search = joint_table.find(sOne, sTwo, position);
                    }

                }
                start = start + len;
            }
            else { start = start + 1; }
        }
       
        if (correct == true) { 
            //lets user know if this pair matched and gave the correct result
            std::cout << "Yes" << endl;
            //adding to the count of correct matches 
            corCount++;
            if (part == true) {
                //adding to count of correct matches that also include parts 
                partCorCount++;
            }
        }
        else { 
            std::cout << "No" << endl; 
            if (part == true) {
                //adding to the count of non-matches that have parts
                partCount++;
            }
        }
        //adding to total count
        count++;      
    }
    //All words being tested are expected to match so the "Expected matches" is just a count off all the matches trialed 
    std::cout << endl << "Expected matches: " << count << endl;
    std::cout << "Total matches: " << corCount << endl;
    //the part matches change based on which language was put down first as only the firstcog has each of its letters checked.
    //the part matches is just being used to see what possible gaps the sound pair table building and file system may currently have
    std::cout << "Total part correct matches: " << partCorCount << endl;
    std::cout << "Total part incorrect matches: " << partCount << endl;
    return 0;
}

//check if the sound is found in the second word 
bool soundmatch(u32string word, u32string sound, int& place) {
 
    // Find first occurrence of sound
    size_t found = word.find(sound);
    if (found != string::npos)
    {
        return true;
    }
       
    return false;
}
