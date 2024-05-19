#include <iostream>
#include <queue>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;

	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num <= k)
			pq.push(num);
	}

	int coinCnt = 0;

	while (k != 0)
	{
		int coin = pq.top();
		coinCnt += k / coin;
		k = k % coin;
		pq.pop();
	}

	cout << coinCnt << endl;
}

