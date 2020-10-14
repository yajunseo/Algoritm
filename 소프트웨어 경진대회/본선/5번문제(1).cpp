#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int arr[300][300] = { 0, };
int n, m;
vector<pair<int, int>>v;
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

	for (int i = 0; i < n; i++)
	{
		pair<int, int> aa;
		int sum = 0;
		for (int j = 0; j < 300; j++)
		{
			if (arr[i][j] == 1)
			{
				sum++;
			}
			aa.first = i;
			aa.second = sum;
		}
		if(sum >= n-1)
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