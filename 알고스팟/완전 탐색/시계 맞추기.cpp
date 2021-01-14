#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
int c;
bool check12();
int pushButtom(int n, int continueCnt, int count);
void chageClock(int t, int n);

int button[10][5]
= {
	{0,1,2,-1,-1},
	{3,7,9,11,-1},
	{4,10,14,15,-1},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15,-1},
	{3,14,15,-1,-1},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13},
};

int arr[16];

int main()
{
	cin >> c;
	while (c > 0)
	{
		int minCount = 999999;

		//memset(&arr, 16, sizeof(arr));
		for (int i = 0; i < 16; i++)
			cin >> arr[i];

		cout << pushButtom(0, 0, 0) << endl;
		c--;
	}

	return 0;
}

bool check12()
{
	for (int i = 0; i < 16; i++)
	{
		if (arr[i] != 12)
			return false;
	}
	return true;
}

void chageClock(int t, int n)
{
	for (int i = 0; i < 5; i++)
	{
		if (button[n][i] != -1)
		{
			int num = button[n][i];
			if (t > 0)
			{
				if (arr[num] == 12)
					arr[num] = 3;
				else
					arr[num] += 3;
			}
			else
			{
				if (arr[num] == 3)
					arr[num] = 12;
				else
					arr[num] -= 3;
			}
		}
	}
	/*for (int i = 0; i < 16; i++)
		cout << arr[i] << " ";
	cout << endl;*/
}

int pushButtom(int n, int continueCnt, int count)
{
	if (check12())
		return count;
	else if (n == 10)
		return -1;
	else if (continueCnt == 3)
		return pushButtom(n + 1, 0, count);

	chageClock(1, n);
	int result1 = pushButtom(n, continueCnt + 1, count + 1);
	chageClock(-1, n);
	int result2 = pushButtom(n + 1, 0, count);

	int minResult = min(result1, result2);

	if (minResult == -1)
		return max(result1, result2);

	return minResult;

	//if (result1 == -1 && result2 == -1)
	//	return -1;
	//else if (minResult == -1)
	//	return max(result1, result2);
	//else
	//	return minResult;
}