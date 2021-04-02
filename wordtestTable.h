#pragma once
#include "wordtest.h"
#include <fstream>
#include <iostream> 
#include <sstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>

extern wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;

class wordtestTable {
	public:
		wordtestTable();
		vector<wordtest> oe_pairs;
		vector<wordtest> la_pairs;
		vector<wordtest> agr_pairs;
		vector<wordtest> the_pairs;
		vector<wordtest> first_pairs;
		vector<wordtest> second_pairs;
		void show();
		void organise(string firstLang, string secondLang);
};

