#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int board[500][500] = { 0 };
int visit[500][500] = { 0 };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int pictureCnt = 0;

int BFS(int i, int j);

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int maxCnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int cnt = BFS(i, j);

			maxCnt = cnt > maxCnt ? cnt : maxCnt;
		}
	}

	cout << pictureCnt << endl;
	cout << maxCnt << endl;
}

int BFS(int i, int j)
{
	int cnt = 0;

	if (board[i][j] != 1)
		return 0;

	if (visit[i][j] == 1)
		return 0;

	pictureCnt++;
	cnt++;
	visit[i][j] = 1;
	
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		auto pair = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int posX = pair.first + dx[k];
			int posY = pair.second + dy[k];

			if (posX < 0 || posX > 499 || posY < 0 || posY > 499)
				continue;

			if (board[posX][posY] != 1)
				continue;

			if (visit[posX][posY] == 1)
				continue;

			visit[posX][posY] = 1;

			q.push(make_pair(posX, posY));

			cnt++;
		}
	}

	return cnt;
}