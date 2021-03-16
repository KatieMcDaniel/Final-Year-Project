#include <iostream>
#include <string>
#include "cogpair.h"
#include "soundpair.h"
#include <vector>

using namespace std;


int main()
{
    string firstCog = "Kardia";
    string secondCog = "Heorta";
    cogpair cogpair(firstCog, secondCog);
   
    string firstLang = "Grk";
    string secondLang = "Ger";
    soundpair sound;
    soundpair soundpair[9];

    int counter = 0;
   
    for (int i = 1; i < 10; i++) {
        //setSoundPair finds the sound pairs between the languages being checked 
        sound.setSoundPair(i, firstLang, secondLang);
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
