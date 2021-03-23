#if !defined SOUNDPAIR
#define SOUNDPAIR

using namespace std;
#include <string>


class soundpair {
public:
	string firstSound;
	string secondSound;
	string firstLang;
	string secondLang;
	int firstPlace;
	int secondPlace;
	bool match;

	soundpair();
	void setSoundPair(int position, string first, string second);
	void setSoundPair(string firstS, string secondS, int firstP, int secondP);
	void getLetter(string lang, int position, string& letter);
};

#endif