#include <iostream>
#include <string>
#include "cogpair.h"
#include "soundpair.h"

using namespace std;

int main()
{
    string firstCog = "kardia";
    string secondCog = "heorta";
    cogpair cogpair(firstCog, secondCog);

    string firstLang = "Agr";
    string secondLang = "La";
    soundpair soundpair(firstLang, secondLang);

    //will have to set this up using pointers and new after csv but for now lets get the bones done this way

    /* 
    for (int i = 0; i < 2; i++) {
        sounds[i].setSoundPair(firstSound[i], secondSound[i]);
    }
        
    bool cognate[2];

    for (int i = 0; i < 2; i++) {
        cognate[i] = pair.cogmatch(sounds[i].firstSound, sounds[i].secondSound, sounds[i].firstPlace, sounds[i].secondPlace);
    }

    for (int i = 0; i < 2; i++) {
        if (cognate[i] == false) {
            cout << "no match found 1" << endl;
            return 0;
        }      
        else {
            if (i != 0) {
                if (sounds[i].firstPlace < sounds[i - 1].firstPlace) {
                    cout << "no match found 2" << endl;
                    return 0;
                }
                if (sounds[i].secondPlace < sounds[i - 1].secondPlace) {
                    cout << "no match found 3" << endl;
                    return 0;
                }
            }
        }
    }

    */

    cout << "I think that is a match" << endl;

    return 0;
}

