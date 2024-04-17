#include <iostream>

using namespace std;

int n, s;
int* arr;
int cnt = 0;

void backTrack(int k, int sum)
{
	if (k == n)
	{
		if (sum == s)
			cnt++;

		return;
	}

	backTrack(k + 1, sum + arr[k]);
	backTrack(k + 1, sum);
}

int main() {
	cin >> n >> s;

	arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	backTrack(0, 0);

	if (s == 0)
		cnt--;

	cout << cnt << endl;
}

