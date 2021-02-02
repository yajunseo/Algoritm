#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>

using namespace std;

int n, m;
int start[201][201];
int arr[201][201] = { 0 };

int main()
{
	for (int i = 1; i < 201; i++)
		for (int j = 1; j < 201; j++)
		{
			if (i != j)
				arr[i][j] = 1000000000;
		}

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		start[a][b] = b;
		start[b][a] = a;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	for (int i = 1; i < 201; i++)
		for (int j = 1; j < 201; j++)
			for (int k = 1; k < 201; k++)
			{
				if (arr[j][k] > arr[j][i] + arr[i][k])
				{
					arr[j][k] = arr[j][i] + arr[i][k];
					start[j][k] = start[j][i];
				}
			}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				cout << "- ";
			else
				cout << start[i][j] << " ";
		}
		cout << endl;
	}
}