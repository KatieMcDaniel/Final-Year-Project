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
		soundpair(string first, string second);
		void setSoundPair(char first, char second);
		void findSound();
};

