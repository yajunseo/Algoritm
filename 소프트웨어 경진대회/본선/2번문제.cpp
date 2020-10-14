#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;

vector<char> v;
vector<char> rv;
vector<char> p;
string s;

bool checkPal()
{
	for (int i = 0; i < p.size() / 2; i++)
	{
		if (p[i] != p[p.size() - 1 - i])
			return false;
	}
	return true;
}

void makePal()
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		rv.push_back(s[i]);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int temp = (int)v[i] - 97 + (int)rv[i] - 97;
		if (temp <= 25)
		{
			p[i] = char(temp + 97);
		}
		else
		{
			int r = temp % 25;
			p[i] = char(r + 97);
		}
	}
}



int main()
{
	cin >> s;
	bool t = false;
	while (!t)
	{
		for (int i = 0; i < s.length(); i++)
		{
			v.push_back(s[i]);
			p.push_back('a');
		}

		makePal();
		t = checkPal();
	}


	/*for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << rv[i];
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << p[i];
	cout << endl;*/
	for (int i = 0; i < v.size(); i++)
		cout << p[i];

	return 0;
}