#pragma once
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <locale>
#include <codecvt>
#include <iostream> 

class langfile
{
	public:
		wstring_convert<codecvt_utf8<char32_t>, char32_t> cvt;
		string firstLang;
		string secondLang;
		u32string firstSound;
		u32string secondSound;
		int firstPlace; 
		int secondPlace;


		langfile(string first, string second);
		void getLetter(int position);
};

