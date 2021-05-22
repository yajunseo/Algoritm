#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1000000000;
int v, e;
int k;
int ls, le, w;
vector<pair<int, int>> vCourse[20001];
int d[20001];

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, start });
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < vCourse[current].size(); i++)
		{
			int next = vCourse[current][i].second;
			int nextDistance = distance + vCourse[current][i].first;
			if (d[next] > nextDistance)
			{
				d[next] = nextDistance;
				pq.push({ -nextDistance, next});
			}
		}
	}
}


int main()
{
	scanf("%d %d", &v, &e);
	scanf("%d", &k);
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &ls, &le, &w);
		vCourse[ls].push_back(make_pair(w, le));
	}

	for (int i = 1; i <= v; i++)
	{
		d[i] = INF;
	}
	dijkstra(k);

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", d[i]);
		}
	}
}
