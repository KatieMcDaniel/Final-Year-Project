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
		bool cogmatch(char first, char second, int& firstPlace, int& secondPlace);
		bool soundmatch(string word, char sound, int& place);
};
