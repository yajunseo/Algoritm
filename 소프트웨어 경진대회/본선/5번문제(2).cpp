#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int arr[300][300] = { 0, };
int n, m;
vector<pair<int, int>>v;
int narr[300] = { 0, };
void initArr()
{
	for (int i = 1; i <= n; i++)
		narr[i] = 0;
}

bool isPass(int num)
{
	int cnt = 0;
	initArr();



	for (int i = 1; i <= n; i++)
	{
		if(i != num)
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1 && j != num)
			{
				cnt++;
			}
		}
	}
	cnt /= 2;
	
	if (cnt < n - 1)
		return true;
	else
		return false;
}

int main()
{
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		pair<int, int> aa;
		int sum = 0;
		for (int j = 1; j < 301; j++)
		{
			if (arr[i][j] == 1)
			{
				sum++;
			}
			aa.first = i;
			aa.second = sum;
		}
		if (isPass(i))
			v.push_back(aa);
	}

	//sort(v.begin(), v.end(), [](auto& left, auto& right) {
	//	return left.second < right.second;
	//});

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << endl;

	return 0;
}