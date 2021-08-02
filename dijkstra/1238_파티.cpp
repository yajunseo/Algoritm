#include <iostream>
#include <queue>
#define INF 99999
using namespace std;
int n, m, x;
vector<pair<int, int>> map[1001];
int dist[1001] = { 0, };

int dijkstra(int s, int e)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[s] = 0;

    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < map[now].size(); i++)
        {
            int next = map[now][i].first;
            int ncost = map[now][i].second;
            if (dist[next] > dist[now] + ncost)
            {
                dist[next] = dist[now] + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    if (dist[e] == INF)
    {
        int a = 3;
    }
    return dist[e];
}

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }

    int maxDist = -1;
    for (int i = 1; i <= n; i++)
    {
        int temp = dijkstra(x, i);
        temp += dijkstra(i, x);
        if (maxDist < temp)
            maxDist = temp;
    }

    cout << maxDist;

    return 0;
}