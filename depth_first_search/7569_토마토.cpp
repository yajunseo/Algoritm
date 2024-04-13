#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int board[100][100][100] = { -1 };
int visit[100][100][100] = { 0 };

int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};
int dz[] = {1, -1, 0, 0, 0, 0};

const int DIRECT_CNT = sizeof(dx) / sizeof(dx[0]);

int finalDay = 0;

int m, n, h;

bool CheckAllTomatoRipen();
int BFS();

int main() {
	cin >> m >> n >> h;

	bool isAllRipen = true;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
			{
				cin >> board[i][j][l];
				if (board[i][j][l] == 0)
					isAllRipen = false;
			}

	if (isAllRipen)
	{
		cout << 0 << endl;
		return 0;
	}

	finalDay = BFS();

	if (!CheckAllTomatoRipen())
	{
		cout << -1 << endl;
		return 0;
	}

	cout << finalDay << endl;
}

bool CheckAllTomatoRipen()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
				if (board[i][j][l] == 0 && visit[i][j][l] == 0)
					return false;

	return true;
}

int BFS()
{
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
			{
				if (board[i][j][l] == 1)
				{
					q.push(tuple<int, int, int>(i, j, l));
				}
			}

	int maxDay = 0;

	while (!q.empty())
	{
		auto prevTomato = q.front();
		q.pop();

		int prevDay = visit[get<0>(prevTomato)][get<1>(prevTomato)][get<2>(prevTomato)];

		for (int i = 0; i < DIRECT_CNT; i++)
		{
			tuple<int, int, int> pos(get<0>(prevTomato) + dz[i], get<1>(prevTomato) + dx[i], get<2>(prevTomato) + dy[i]);
			
			if(get<0>(pos) < 0 || get<0>(pos) >= h
				|| get<1>(pos) < 0 || get<1>(pos) >= n
				|| get<2>(pos) < 0 || get<2>(pos) >= m)
				continue;

			if (board[get<0>(pos)][get<1>(pos)][get<2>(pos)] != 0)
				continue;

			if (visit[get<0>(pos)][get<1>(pos)][get<2>(pos)] != 0)
				continue;

			int currentDay = prevDay + 1;
			visit[get<0>(pos)][get<1>(pos)][get<2>(pos)] = currentDay;

			maxDay = currentDay;

			q.push(pos);
		}
	}

	return maxDay;
}