#include <iostream>

using namespace std;

int main() {
	int n, k;
	int ans = 0;
	cin >> n >> k;

	int arr[15];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > k)
			continue;

		ans += k / arr[i];
		k %= arr[i];

		if (k == 0)
			break;
	}
	
	cout << ans << endl;
}

