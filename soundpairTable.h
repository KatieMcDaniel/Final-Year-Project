#if !defined SOUNDPAIR_TABLE
#define SOUNDPAIR_TABLE

#include "soundpair.h"
#include <fstream>
#include <iostream> 
#include <sstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>

using namespace std;

extern wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

class soundpairTable {
	public:
		soundpairTable();
		soundpairTable(string table_name, int type);
		soundpairTable(vector<soundpair> first_pairs, vector<soundpair> second_pairs);
		vector<soundpair> the_pairs;

		void show();
		bool find(u32string firstSound, u32string& secondSound, int& pos);
		void sort();
		bool longest_prefix(u32string input, int start, int& index, int& len, u32string& one, u32string& two);
};

#endif
