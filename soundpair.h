using namespace std;
#include <string>

class soundpair {
	public:
		//wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;
		u32string firstSound;
		u32string secondSound;
		int firstPlace;
		int secondPlace;
		bool match;

		soundpair();
		void setSoundPair(u32string firstS, u32string secondS, int firstP, int secondP);
	
};



