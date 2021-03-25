#if !defined SOUNDPAIR
#define SOUNDPAIR

using namespace std;
#include <string>

class soundpair {
public:
	u32string firstSound;
	u32string secondSound;
	string firstLang;
	string secondLang;
	
	soundpair();
};
#endif