#include <iostream>
using namespace std;
int n, m;
int friendArr[10][10] = { 0, };
int mate[10] = { 0, };

void initArr()
{
	for (int i = 0; i < 10; i++)
	{
		mate[i] = 0;
		for (int j = 0; j < 10; j++)
		{
			friendArr[i][j] = 0;
		}
	}
}

int findMate(int* arr)
{
	int cnt = 0;
	int p = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			p = i;
			break;
		}
	}
	if (p == -1) return 1;

	for (int i = p + 1; i < n; i++)
	{
		if (friendArr[p][i] == 1 && arr[i] == 0)
		{
			arr[i] = arr[p] = 1;
			cnt += findMate(arr);
			arr[i] = arr[p] = 0;
		}
	}
	return cnt;
}

int main()
{
	int c;
	cin >> c;
	while (c > 0)
	{
		initArr();
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int f1, f2;
			cin >> f1 >> f2;
			friendArr[f1][f2] = friendArr[f2][f1] = 1;
		}
		cout << findMate(mate) << endl;
		c--;
	}

	return 0;
}