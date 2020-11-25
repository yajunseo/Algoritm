#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
int n;
int arr[15][2] = { 0, };
int cost[15] = { 0, };

vector <int> *v;

void calculateMaxMoney(int date, int money)
{
	int tMoney = money;

	if (date >= n)
		return;


	for (int i = 0; i < 5; i++)
	{
		if (arr[date][0] + date + i <= n)
		{
			if (cost[date] < tMoney + arr[date][1])
				cost[date] = tMoney + arr[date][1];


			calculateMaxMoney(arr[date][0] + date + i, tMoney + arr[date][1]);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < arr[0][0]; i++)
	{
		if (i == 3)
			int a = 3;
		calculateMaxMoney(i, 0);
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (cost[i] > max)
			max = cost[i];
	}

	cout << max << endl;
	return 0;
}
