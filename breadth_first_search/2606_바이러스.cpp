#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[101] = {0,};
int netArr[101][101] = { 0, };

int main()
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		netArr[a][b] = 1;
		netArr[b][a] = 1;

	}

	queue<int> q;

	q.push(1);
	int infect = -1;
	arr[1] = 1;

	while (!q.empty())
	{
		int t = q.front();
		infect++;

		//cout << t << endl;
		q.pop();
		for (int i = 1; i < n + 1; i++)
		{
			if (netArr[t][i] == 1)
				if (arr[i] == 0)
				{
					arr[i] = 1;
					q.push(i);
				}
		}
	}

	cout << infect << endl;

	return 0;
}