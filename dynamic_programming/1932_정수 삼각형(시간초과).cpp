#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int n;

int findIndex(int m, int n)
{
	int p = 0;
	if (m == 0)
		return 0;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			p++;
			if (i == m && j == n)
				return p;
		}
	}
}

int findMax(int i, int j, int sum)
{
	int add = sum;
	add += v[findIndex(i, j)];

	int temp1 = add, temp2 = add;
	if (i < n - 1)
	{
		temp1 = findMax(i + 1, j, add);
		temp2 = findMax(i + 1, j + 1, add);
	}

	else
		return add;

	return (temp1 > temp2) ? temp1 : temp2;
}


int main()
{
	int m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> m;
			v.push_back(m);
		}
	}

	if (n == 1)
		return v[0];
	else
		cout << findMax(0, 0, 0) << endl;

	return 0;
}