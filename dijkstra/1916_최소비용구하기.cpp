#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#define INF 1999999999
using namespace std;

int n, m;
int s, e;

// 비용, 도착지
vector<pair<int, int>> v[1001];
int arr[1001];

void dijkstra(int start)
{
	arr[s] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = pq.top().first;
		pq.pop();
		if (arr[current] < distance) continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].second;
			int nextDistance = distance + v[current][i].first;
			if (arr[next] > nextDistance)
			{
				arr[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}


int main()
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		v[n1].push_back(pair<int, int>(n3, n2));
	}

	for (int i = 1; i <= n; i++)
		arr[i] = INF;


	cin >> s >> e;

	dijkstra(s);

	cout << arr[e];
	return 0;
}
