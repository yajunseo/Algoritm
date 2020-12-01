#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
string s;
bool sameNum = false;

int checkMin()
{
	int cnt = 0;
	char c = s[0];

	for (int i = 0; i < s.length(); i++)
	{
		if (!sameNum && s[i] != c)
		{
			sameNum = true;
			cnt++;
		}

		else if (sameNum && s[i] == c)
		{
			sameNum = false;
		}
	}
	return cnt;
}

int main()
{
	cin >> s;
	cout << checkMin() << endl;
	return 0;
}
