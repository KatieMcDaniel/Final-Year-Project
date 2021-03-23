#include "soundpair.h"

//soundpair constructer 
soundpair::soundpair()
    :firstSound(), secondSound(), firstPlace(0), secondPlace(0), match()
{}

//sets the sound pair params for when its trying out multiple sound shifts 
//yeah should defos be a seperate class for doing this tbh...


//sets the soundpair params when its known that the sound shifft matches up 
void soundpair::setSoundPair(u32string firstS, u32string secondS, int firstP, int secondP) {
     firstSound = firstS;
     secondSound = secondS;
     firstPlace = firstP;
     secondPlace = secondP; 
     match = true;
}

