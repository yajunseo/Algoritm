#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int m, n;
int s;
char arr[1000][1000];
int Iarr[1000][1000] = { 0, };
vector<int> v;
vector<int> v2;

int findCloud(int i, int j)
{
	int sum = 0;
	if (i < 0 || j < 0 || i >= m || j >= n)
		return sum;

	if (Iarr[i][j] == 2)
		return sum;

	if (Iarr[i][j] == 1)
	{
		sum++;
		Iarr[i][j] = 2;
	}

	int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0,
		temp5 = 0, temp6 = 0, temp7 = 0, temp8 = 0;

	temp1 = findCloud(i + 1, j);
	temp2 = findCloud(i - 1, j);
	temp3 = findCloud(i , j + 1);
	temp4 = findCloud(i, j - 1);
	temp5 = findCloud(i + 1, j + 1);
	temp6 = findCloud(i - 1, j - 1);
	temp7 = findCloud(i - 1, j + 1);
	temp8 = findCloud(i + 1, j - 1);

	sum += (temp1 + temp2 + temp3 + temp4 + temp5 + temp6 + temp7 + temp8);

	return sum;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '.')
				Iarr[i][j] = 1;
			else if (arr[i][j] == '#')
				Iarr[i][j] = 2;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Iarr[i][j] == 1)
				v.push_back(findCloud(i, j));
		}
	}

	cin >> s;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= s)
		{
			v2.push_back(v[i]);
		}
	}

	int max = 0;
	for (int i = 0; i < v2.size(); i++)
	{
		if (max < v2[i])
			max = v2[i];
	}

	cout << v2.size() << " " << max << endl;
	return 0;
}