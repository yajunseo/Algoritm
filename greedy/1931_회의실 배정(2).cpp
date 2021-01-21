#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>> v;
int main()
{
	int temp[2];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> temp[j];
		}
		pair<int, int> p;
		p.first = temp[0];
		p.second = temp[1];
		v.push_back(p);
	}

	sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second)
		{
			return a.first < b.first;
		}
		return a.second < b.second;
	});

	int m = 0;
	m = v[0].second;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (m <= v[i].first)
		{
			cnt++;
			m = v[i].second;
		}
	}

	cout << cnt << endl;

	return 0;
}
