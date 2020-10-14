#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
string s;
string t;
int notAcnt = 0;
int arr[20] = { 0, };

int joystick(int num)
{
	int cnt = 0;

	if (s[num] < 'N')
	{
		//cout << s[num] - t[num] << endl;
		return s[num] - t[num];
	}
	else
	{
		t[num] = 'Z' + 1;
		/*cout << t[num] - s[num] << endl;*/
		return t[num] - s[num];
	}
}

int main()
{
	int cnt = 0;
	int left = 100, right = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		t += "A";
		if (s[i] != 'A')
			notAcnt++;
		else
		{
			if (i < left)
				left = i;
			if (right < i)
				right = i;
		}
	}


	int tleft = left - 0, tright = s.size() - 1 - right;



	if (tright > tleft)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (notAcnt == 0)
				break;

			if (s[i] != 'A')
			{
				cnt += joystick(i);
				notAcnt--;
			}

			if (notAcnt == 0)
				break;

			if (i != (s.size() - 1))
				cnt++;
		}
	}
	else
	{
		if (s[0] != 'A')
		{
			cnt += joystick(0);
			notAcnt--;
		}
		cnt++;
		if (s[0])
			for (int i = s.size() - 1; i > 0; i--)
			{
				if (notAcnt == 0)
					break;

				if (s[i] != 'A')
				{
					cnt += joystick(i);
					notAcnt--;
				}

				if (notAcnt == 0)
					break;

				if (i != 1)
					cnt++;
			}
	}

	cout << cnt << endl;

	return 0;
}