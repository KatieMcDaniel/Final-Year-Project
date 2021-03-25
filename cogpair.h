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

	cogpair();
	bool soundmatch(u32string word, u32string sound, int& place);
};

#endif