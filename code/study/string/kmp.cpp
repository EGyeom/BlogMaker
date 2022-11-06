#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern)
{
	int patternSize = pattern.length();
	vector<int> table(patternSize, 0);
	int j = 0;
	for(int i = 1; i < patternSize; i++)
	{
		while(j > 0 && pattern[i] != pattern[j])
			j = table[j-1];

		if(pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}

	return table;
}

void KMP(string s, string pattern)
{
	vector<int> table = makeTable(pattern);
	int sSize = s.length();
	int patternSize = pattern.length();
	int j = 0;
	for(int i = 0; i < sSize; i++)
	{
		while(j > 0 && s[i] != pattern[j])
			j = table[j-1];
		
		if(s[i] == pattern[j])
		{
			j++;
			if(j == patternSize)
			{
				cout << "Pattern Matched ! index : " << i - j + 2 << "\n";
				j = table[j-1];
			}
		}
	}
}


int main()
{
	/* 
	ABC ABCDAB ABCDABCDABDE
	ABCDABD
 	
	abacabacabababacabab
	abacabab

	ababacabacaabacaaba
	abacaaba
	*/

	string s = "ABC ABCDAB ABCDABCDABDE";
	string pattern = "ABCDABD";
	KMP(s,pattern);
}