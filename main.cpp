#include <iostream>
#include <string>
#include "cogpair.h"
#include "soundpair.h"
#include "soundpairTable.h"
#include <vector>

using namespace std;

soundpairTable first_table;
soundpairTable second_table;

int main()
{
    string firstCog = "kardia";
    string secondCog = "heorta";
    cogpair cogpair(firstCog, secondCog);
   
    string firstLang = "Grk";
    string secondLang = "Ger";

    // these lines create appropriate first_table and second_table
    if (firstLang == "Ger") { first_table = soundpairTable("Tables/sound_evol_pie_ger_no_alts.csv"); }
    if (firstLang == "Grk") { first_table = soundpairTable("Tables/sound_evol_pie_grk(rom_orth).csv"); }
    if (firstLang == "Lat") { first_table = soundpairTable("Tables/sound_evol_pie_lat.csv"); }

    if (secondLang == "Ger") { second_table = soundpairTable("Tables/sound_evol_pie_ger_no_alts.csv"); }
    if (secondLang == "Grk") { second_table = soundpairTable("Tables/sound_evol_pie_grk(rom_orth).csv"); }
    if (secondLang == "Lat") { second_table = soundpairTable("Tables/sound_evol_pie_lat.csv"); }

    first_table.show();
    second_table.show();
	
    //need to sort out this stuffs 
    soundpair sound;
    soundpair soundpair[9];

    int counter = 0;

    // counting from 0 in the tables
    for (int i = 0; i < 9; i++) {
      //setSoundPair finds the sound pairs between the languages being checked
      //sound.setSoundPair(i, firstLang, secondLang);
      //emms: above replaced by
      sound.firstLang = first_table.the_pairs[i].secondLang;
      sound.firstSound = first_table.the_pairs[i].secondSound;
      sound.secondLang = second_table.the_pairs[i].secondLang;
      sound.secondSound = second_table.the_pairs[i].secondSound;
      

      cout << "Checking for matches with: " << sound.firstSound << " and " << sound.secondSound << endl;
      //cogmatch checks to see if the sound pair is present between the two words being checked 
      sound.match = cogpair.cogmatch(sound.firstSound, sound.secondSound, sound.firstPlace, sound.secondPlace);
      //if the match occurs then the soundpair is saved in an array 
      if (sound.match == true) {
	soundpair[counter].setSoundPair(sound.firstSound, sound.secondSound, sound.firstPlace, sound.secondPlace);
	counter++;
      }
    }

    if (counter == 0) {
        cout << "No matches found!" << endl;
    }
    if (counter > 1) {
        //if more than one sound pair occurs then it must be checked that the placement of the sounds is in the correct order
        int n = 0;
        for (int i = 0; i < counter; i++)
        {
            for (int j = 0; j < counter; j++)
            {
                if (((soundpair[i].firstPlace > soundpair[j].firstPlace) && (soundpair[i].secondPlace < soundpair[j].secondPlace))
                    || ((soundpair[i].firstPlace < soundpair[j].firstPlace) && (soundpair[i].secondPlace > soundpair[j].secondPlace)))
                {
                    soundpair[i].match = false;
                }
            }
        }  
        
        for (int i = 0; i < counter; i++) {
            if (soundpair[i].match == true) {
                cout << "Match found! Sounds: " << soundpair[i].firstSound << " and " << soundpair[i].secondSound << endl;
                n++;
            }
        }
        // n keeps track of the sound pairs to check if any of them were valid. 
        if (n == 0) {
            cout << "No matches found!" << endl;
        }
    }
    if (counter == 1) {
        cout << "One match found! Sounds: " << soundpair[0].firstSound << " and " << soundpair[0].secondSound << endl; 
    }
    
    return 0;
}
