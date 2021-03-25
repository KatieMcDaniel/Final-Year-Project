#include "cogpair.h"
#include <string>
using namespace std;

//cogpair constructer 
cogpair::cogpair()
	: firstWord(), secondWord(), firstSound(), secondSound(), match()
{}


//check where the sound is found in the word 
bool cogpair::soundmatch(u32string word, u32string sound, int& place) {
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