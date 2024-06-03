#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int** linkArr = new int*[n];
	int* visit = new int[n];
	memset(visit, 0, n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		linkArr[i] = new int[n];
		memset(linkArr[i], 0, n * sizeof(int));
	}

	for (int i = 0; i < k; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		linkArr[n1 - 1][n2 - 1] = 1;
		linkArr[n2 - 1][n1 - 1] = 1;
	}

	int answer = 0;
	queue<int> q;

	q.push(0);
	visit[0] = 1;

	while (!q.empty())
	{
		int index = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (visit[i] == 1)
				continue;

			if (linkArr[index][i] == 0)
				continue;

			q.push(i);
			visit[i] = 1;
			answer++;
		}
	}

	cout << answer << endl;
}

