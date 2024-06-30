#include <iostream>

using namespace std;

int n, s;
int arr[25];

int func(int cur, int sum)
{
	if (cur == n)
	{
		return sum == s ? 1 : 0;
	}

	return func(cur + 1, sum) + func(cur + 1, sum + arr[cur]);
}

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int cnt = func(0, 0);

	if (s == 0)
		cnt--;

	cout << cnt;
}

