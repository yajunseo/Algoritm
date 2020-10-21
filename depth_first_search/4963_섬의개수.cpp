#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int arr[50][50] = { 0, };
int w = -1, h = -1;
int cntTerrain = 0;
vector<int> v;

int checkIsland(int a, int b)
{
	int sum = 0;
	if (a < 0 || b < 0 || a >= h || b >= w)
		return 0;

	if (cntTerrain <= 0)
		return 0;

	if (arr[a][b] == 0)
		return 0;

	if (arr[a][b] == 1)
	{
		arr[a][b] = 0;
		sum++;
		cntTerrain--;
	}

	sum += checkIsland(a-1, b-1);
	sum += checkIsland(a-1, b);
	sum += checkIsland(a-1, b+1);
	sum += checkIsland(a, b-1);
	sum += checkIsland(a, b+1);
	sum += checkIsland(a+1, b-1);
	sum += checkIsland(a+1, b);
	sum += checkIsland(a+1, b+1);
	return sum;
}

int main()
{
	int check = 0;
	while (1)
	{
		check = 0;
		cntTerrain = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					cntTerrain++;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1)
				{
					if (checkIsland(i, j) >= 1)
						check++;
				}
			}
		}

		v.push_back(check);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}