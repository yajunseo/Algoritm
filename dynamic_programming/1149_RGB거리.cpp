#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int n;

int arr[1001][4];

typedef struct colorCost
{
	int red;
	int green;
	int blue;
}ColorCost;

ColorCost* c;

int findMinCost(int num, int choice);


int main()
{
	cin >> n;

	c = new ColorCost[n+1];
	int t;
	for (int i = 1; i < n+1; i++)
	{
		cin >> c[i].red >> c[i].green >> c[i].blue;
	}

	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = -1;
		}
	}

	cout << findMinCost(1, 3) << endl;



	return 0;
}


int findMinCost(int num, int choice)
{
	if (num > n)
		return 0;

	if (arr[num][choice] != -1)
		return arr[num][choice];

	int val1 = 999999999 , val2 = 999999999, val3 = 999999999;


	if (choice % 3 != 0 || choice == 3)
	{
		val1 = c[num].red + findMinCost(num + 1, 0);
	}

	if (choice % 3 != 1 || choice == 3)
	{
		val2 = c[num].green + findMinCost(num + 1, 1);
	}

	if (choice % 3 != 2 || choice == 3)
	{
		val3 = c[num].blue + findMinCost(num + 1, 2);
	}

	return arr[num][choice] = min(val1, min(val2, val3));
}