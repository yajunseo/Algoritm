#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
char c[500];
char c2[500];
bool check = true;

void putPoly(int start, int end)
{
	int len = end - start + 1;
	if (len % 4 == 0)
	{
		for (int i = start; i <= end; i++)
			c2[i] = 'A';
	}
	else if (len % 4 == 2)
	{
		if(len == 2)
			for (int i = start; i <= end; i++)
				c2[i] = 'B';
		else
		{
			for (int i = start; i <= end - 1; i++)
				c2[i] = 'A';
			for (int i = end - 1; i <= end; i++)
				c2[i] = 'B';
		}
	}
	else
	{
		check = false;
	}
}

void poly()
{
	int start = 0, end = 0;
	bool cs = false, ce = false;
	int cnt = 0;
	int n = strlen(c);
	while(cnt < n && check)
	{
		if (!cs && c[cnt] != '.')
		{
			start = cnt;
			cs = true;
		}
		if (cs && !ce && (c[cnt + 1] == '.' || cnt + 1 == n))
		{
			end = cnt;
			ce = true;
		}
		if (cs && ce)
		{
			cs = false;
			ce = false;
			putPoly(start, end);
		}
		cnt++;
	}

}

int main()
{
	cin >> c;
	//strcpy_s(c2, c);

	for (int i = 0; i < strlen(c); i++)
	{
		c2[i] = c[i];
	}
	poly();
	if (check)
	{
		cout << c2 << endl;
	}
	else
		cout << "-1" << endl;

	return 0;
}
