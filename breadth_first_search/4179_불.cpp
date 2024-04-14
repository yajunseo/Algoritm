#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

char board[1000][1000] = { "X"};
int jihunVisit[1000][1000] = { 0 };
int fireVisit[1000][1000] = { 0 };

int jihunTime[1000][1000] = { 0 };
int fireTime[1000][1000] = { 0 };

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0 ,1, -1 };

int r, c;

const int DIRECT_CNT = 4;
const char JIHUN = 'J';
const char FIRE = 'F';

void fireBFS();
int JihunBFS(int y, int x);

int main() {
	cin >> r >> c;

	pair<int, int> jPos;
	pair<int, int> fPos;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == JIHUN)
				jPos = make_pair(i, j);
		}

	if (jPos.first == 0
		|| jPos.first == r - 1
		|| jPos.second == 0
		|| jPos.second == c - 1)
	{
		cout << 1 << endl;
		return 0;
	}

	fireBFS();

	int exitTime = JihunBFS(jPos.first, jPos.second);

	if (exitTime == -1)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	cout << exitTime << endl;
}

void fireBFS()
{
	queue<pair<int, int>> fireQueue;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == FIRE)
			{
				fireQueue.push(make_pair(i, j));
				fireVisit[i][j] = 1;
			}
		}

	while (!fireQueue.empty())
	{
		auto prevPos = fireQueue.front();
		fireQueue.pop();
		int prevTime = fireTime[prevPos.first][prevPos.second];

		pair<int, int> newPos;

		for (int i = 0; i < DIRECT_CNT; i++)
		{
			newPos.first = prevPos.first + dx[i];
			newPos.second = prevPos.second + dy[i];

			if (newPos.first < 0 || newPos.first >= r
				|| newPos.second < 0 || newPos.second >= c)
				continue;

			if (fireVisit[newPos.first][newPos.second] != 0)
				continue;

			if (board[newPos.first][newPos.second] == 'F'
				|| board[newPos.first][newPos.second] == '#')
				continue;


			int newTime = prevTime + 1;
			fireTime[newPos.first][newPos.second] = newTime;
			fireVisit[newPos.first][newPos.second] = 1;

			fireQueue.push(newPos);
		}
	}
}

int JihunBFS(int x, int y)
{
	queue<pair<int, int>> jihunQueue;
	jihunQueue.push(make_pair(x, y));
	jihunVisit[x][y] = 1;

	while (!jihunQueue.empty())
	{
		auto prevPos = jihunQueue.front();
		jihunQueue.pop();
		int prevTime = jihunTime[prevPos.first][prevPos.second];

		pair<int, int> newPos;

		for (int i = 0; i < DIRECT_CNT; i++)
		{
			newPos.first = prevPos.first + dx[i];
			newPos.second = prevPos.second + dy[i];

			int newTime = prevTime + 1;

			if (newPos.first < 0 || newPos.first >= r
				|| newPos.second < 0 || newPos.second >= c)
				return newTime;

			if (jihunVisit[newPos.first][newPos.second] != 0)
				continue;

			if (board[newPos.first][newPos.second] == 'F'
				|| board[newPos.first][newPos.second] == '#')
				continue;

			if (fireTime[newPos.first][newPos.second] != 0
				&& newTime >= fireTime[newPos.first][newPos.second])
				continue;

			jihunTime[newPos.first][newPos.second] = newTime;
			jihunVisit[newPos.first][newPos.second] = 1;

			jihunQueue.push(newPos);
		}
	}

	return -1;
}
