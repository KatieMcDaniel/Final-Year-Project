#include "cogpair.h"
#include "soundpair.h"
#include "langfile.h"

using namespace std;

wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

int main()
{
    string firstCog = "darkia";
    string secondCog = "heorta";
    cogpair cogpair(cvt.from_bytes(firstCog), cvt.from_bytes(secondCog));
   
    string firstLang = "Grk";
    string secondLang = "Ger";
    langfile lang(firstLang, secondLang);
    soundpair soundpair[9];
    bool match;


    int counter = 0;
   
    for (int i = 2; i < 10; i++) {
        //setSoundPair finds the sound pairs between the languages being checked 
        lang.getLetter(i);
        cout << "Checking for matches with: " << cvt.to_bytes(lang.firstSound) << " and " << cvt.to_bytes(lang.secondSound) << endl;
        //cogmatch checks to see if the sound pair is present between the two words being checked 
        match = cogpair.cogmatch(lang.firstSound, lang.secondSound, lang.firstPlace, lang.secondPlace);
        //if the match occurs then the soundpair is saved in an array 
        if (match == true) {
            soundpair[counter].setSoundPair(lang.firstSound, lang.secondSound, lang.firstPlace, lang.secondPlace);
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
                cout << "Match found! Sounds: " << cvt.to_bytes(soundpair[i].firstSound) << " and " << cvt.to_bytes(soundpair[i].secondSound) << endl;
                n++;
            }
        }
        // n keeps track of the sound pairs to check if any of them were valid. 
        if (n == 0) {
            cout << "No matches found!" << endl;
        }
    }
    if (counter == 1) {
        cout << "One match found! Sounds: " << cvt.to_bytes(soundpair[0].firstSound) << " and " << cvt.to_bytes(soundpair[0].secondSound) << endl;
    }
    
    return 0;
}
