#include <iostream>
#include <queue>
#include <vector>
#define INF 1999999999
#define min(m1, m2) ((m1 < m2) ? m1 : m2)
using namespace std;

int n, e;
int a, b, c;
int v1, v2;

vector<pair<int, int>> v[801];
int arr[801];

void dijkstra(int start)
{
	arr[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (arr[current] < distance) continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].second;
			int nextDistance = distance + v[current][i].first;

			if (arr[next] > nextDistance)
			{
				arr[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}
}

void init()
{
	for (int i = 1; i <= n; i++)
		arr[i] = INF;
}

int main()
{
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(pair<int, int>(c, b));
		v[b].push_back(pair<int, int>(c, a));
	}

	cin >> v1 >> v2;

	init();

	dijkstra(1);
	if (arr[v1] == INF || arr[v2] == INF || arr[n] == INF)
		cout << "-1" << endl;

	else if (v1 == 1)
	{
		int path = arr[v2];
		init();
		dijkstra(v2);
		path += arr[n];
		cout << path << endl;
	}

	else if (v2 == n)
	{
		int path = arr[v1];
		init();
		dijkstra(v1);
		path += arr[n];
		cout << path << endl;
	}

	else
	{
		int path1 = arr[v1];
		init();
		dijkstra(v1);
		path1 += arr[v2];
		init();
		dijkstra(v2);
		path1 += arr[n];

		init();
		dijkstra(1);
		int path2 = arr[v2];
		init();
		dijkstra(v2);
		path2 += arr[v1];
		init();
		dijkstra(v1);
		path2 += arr[n];

		cout << min(path1, path2) << endl;
	}

	return 0;
}