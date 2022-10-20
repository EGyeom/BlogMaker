#include <iostream>
#include <string>

using namespace std;

bool naiveStringSearch(string s, string p /*Pattern*/)
{
	int n = s.size();
	int m = p.size();

	for(int i =0; i <= n-m; i++)
	{
		int count = 0;
		for(int j =0; j < m; j++)
		{
			cout << s[i+j] << " " << p[j] << "\n";
			if(s[i+j] == p[j])
			{
				count++;
			}
			else break;
		}
		if(count == m)
			return true;
	}

	return false;
}

int main()
{
	string s = "ayzabcde";
	string p = "abc";

	cout << "Pattern is Matched : " << boolalpha << naiveStringSearch(s,p) << "\n";
}