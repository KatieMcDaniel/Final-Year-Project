#if !defined COGPAIR
#define COGPAIR

using namespace std;
#include <string>

class cogpair {
public:
	string firstWord;
	string secondWord;
	string firstSound;
	string secondSound;
	bool match;

	cogpair(string first, string second);
	bool cogmatch(string first, string second, int& firstPlace, int& secondPlace);
	bool soundmatch(string word, string sound, int& place);
};

#endif