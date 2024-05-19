#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;

		pq.push({ -e, -s });
	}

	int lecture = 1;
	int lastEnd = -pq.top().first;
	pq.pop();

	while (!pq.empty())
	{
		auto time = pq.top();
		int start = -time.second;
		int end = -time.first;
		if (lastEnd <= start)
		{
			lecture++;
			lastEnd = end;
		}

		pq.pop();
	}

	cout << lecture << endl;
}

