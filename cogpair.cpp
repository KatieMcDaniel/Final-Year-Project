#include "cogpair.h"

//cogpair constructer 
cogpair::cogpair(u32string first, u32string second) 
	: firstWord(first), secondWord(second), firstSound(), secondSound(), match()
{}

//find if words are cognates 
bool cogpair::cogmatch(u32string first, u32string second, int& firstPlace, int& secondPlace) {
	firstSound = first;
	secondSound = second;

	bool firstMatch = soundmatch(firstWord, firstSound, firstPlace);
	if (firstMatch == true) {
		bool secondMatch = soundmatch(secondWord, secondSound, secondPlace);
		if (firstMatch == true && secondMatch == true) {
			return true;
		}
	}
	
	return false;
}

//check where the sound is found in the word 
bool cogpair::soundmatch(u32string word, u32string sound, int& place) {
	int l = word.length();

	for (int i = 0; i <= l; i++) {
		u32string s(1, word[i]);
		if (s == sound) {
			place = i;
			return true;
		}
	}
	return false;
}

/*
MAke sure that the thing doesnt stop reading after it finds a matching pair. 
However when it does find a matching pair it should send it forwards as being a 'match'
Add in function for checking where the letters appear in the thing here 
Question whether or not soundpair is really needed 
*/