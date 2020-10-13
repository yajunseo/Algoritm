#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[501][501] = { 0, };


int findMax()
{
	int max = 0;

	for (int a = 1; a < n; a++)
	{
		for (int b = 0; b <= a; b++)
		{
			if (b == 0) arr[a][b] += arr[a - 1][b];
			else if (b == a) arr[a][b] += arr[a - 1][b - 1];
			else arr[a][b] += (arr[a - 1][b - 1] > arr[a - 1][b]) ? (arr[a - 1][b - 1]) : (arr[a - 1][b]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (max < arr[n - 1][i])
			max = arr[n - 1][i];
	}

	return max;
}


int main()
{
	int m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	if (n == 1)
		return arr[0][0];
	else
		cout << findMax() << endl;
		
	return 0;
}