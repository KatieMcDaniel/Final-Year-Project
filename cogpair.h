using namespace std;
#include <string>

class cogpair {
	public:
		u32string firstWord;
		u32string secondWord;
		u32string firstSound;
		u32string secondSound;
		bool match;
		
		cogpair(u32string first, u32string second);
		bool cogmatch(u32string first, u32string second, int& firstPlace, int& secondPlace);
		bool soundmatch(u32string word, u32string sound, int& place);
};
