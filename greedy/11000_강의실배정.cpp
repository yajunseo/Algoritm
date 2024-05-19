#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> s_pq;
priority_queue<pair<int, int>> f_pq;

int room = 1;

void CheckLectureEmpty(pair<int, int> time)
{
	auto prevTime = f_pq.top();
	int strat = -prevTime.second;
	int end = -prevTime.first;

	if (-time.first < end)
	{
		room++;
	}

	else
	{
		f_pq.pop();
	}

	f_pq.push({ time.second, time.first });
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		s_pq.push({ -start, -end });
	}

	auto time = s_pq.top();
	s_pq.pop();
	f_pq.push({ time.second, time.first });

	while (!s_pq.empty())
	{
		CheckLectureEmpty(s_pq.top());
		s_pq.pop();
	}

	cout << room << endl;
}

