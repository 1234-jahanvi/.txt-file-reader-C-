#ifndef IMT2019506_h_
#define IMT2019506_h_
#include <bits/stdc++.h>
#include "../filereader.h"

using namespace std;

class IMT2019506:public filereader
{
	private:

		unsigned long long int lines;
		unsigned long long int words;
		unsigned long long int bytes;
		unsigned long long int characters;
		unsigned long long int spaces;
		unsigned long long int charactersNoSpaces;

	public:

		IMT2019506(string input, string output);
		~IMT2019506();
		bool toTake(char ch);
		void input();
    		void run();
    		void output();
};

#endif
