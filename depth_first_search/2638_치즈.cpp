#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[100][100] = { 0, };
int arr2[100][100] = { 0, };

bool checkAllMelt();
bool checkTwoSide(int a, int b);
void updateInside(int a, int b);

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}

	int time = 0;

	while (1)
	{
		if (checkAllMelt())
			break;

		updateInside(0, 0);


		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
			{
				if(arr[i][j] == 1 && checkTwoSide(i, j))
					arr2[i][j] = 2;
			}


		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
			{
				if (arr2[i][j] == 2)
					arr[i][j] = 0;
			}
		//cout << endl << endl;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << arr2[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		time++;
	}

	printf("%d\n", time);
}

bool checkAllMelt()
{
	bool b = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
				b = false;

			arr2[i][j] = 0;
		}

	if (b)
		return true;

	else
		return false;
}

bool checkTwoSide(int a, int b)
{
	int side = 0;


	if (arr2[a - 1][b] == -1)
		side++;

	if (arr2[a + 1][b] == -1)
		side++;

	if (arr2[a][b - 1] == -1)
		side++;

	if (arr2[a][b + 1] == -1)
		side++;
	
	if (side >= 2)
		return true;

	else
		return false;
}

void updateInside(int a, int b)
{
	if (a >= n)
		return;
	if (b >= m)
		return;

	if (a < 0)
		return;
	if (b < 0)
		return;

	if (arr2[a][b] == -1)
		return;


	if (arr[a][b] == 1)
		return;

	else
		arr2[a][b] = -1;

	updateInside(a + 1, b);
	updateInside(a , b + 1);
	updateInside(a - 1, b);
	updateInside(a, b - 1);
}