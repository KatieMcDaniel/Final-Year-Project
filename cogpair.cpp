#include "cogpair.h"
#include <string>
using namespace std;

//cogpair constructer 
cogpair::cogpair(string first, string second) 
	: firstWord(first), secondWord(second), firstSound(), secondSound(), match()
{}

//find if words are cognates 
bool cogpair::cogmatch(char first, char second, int& firstPlace, int& secondPlace) {
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
bool cogpair::soundmatch(string word, char sound, int& place) {
	int l = word.length();

	string s(1, l);

	for (int i = 0; i <= l; i++) {
		if (word[i] == sound) {
			place = i;
			return true;
		}
	}
	return false;
}


