#include <iostream>

using namespace std;

int GetMin(int a, int b)
{
	return a < b ? a : b;
}

int main() {
	int n;
	cin >> n;

	int** arr = new int*[n];
	int** cost = new int*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[3];
		cost[i] = new int[3];

		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	cost[0][0] = arr[0][0];
	cost[0][1] = arr[0][1];
	cost[0][2] = arr[0][2];

	for (int i = 1; i < n; i++)
	{
		cost[i][0] = GetMin(cost[i - 1][1], cost[i - 1][2]) + arr[i][0];
		cost[i][1] = GetMin(cost[i - 1][0], cost[i - 1][2]) + arr[i][1];
		cost[i][2] = GetMin(cost[i - 1][0], cost[i - 1][1]) + arr[i][2];
	}

	int min = GetMin(cost[n - 1][0], cost[n - 1][1]);
	min = GetMin(min, cost[n - 1][2]);

	cout << min << endl;
}

