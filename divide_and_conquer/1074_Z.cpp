#include <iostream>

using namespace std;

int n, r, c;

int selfPow(int a, int b);

int main()
{
	cin >> n >> r >> c;
	r++;
	c++;
	long long cnt = 0;

	while (c > 2 || r > 2)
	{
		int t = selfPow(2, n - 1);
		if (c > t && r <= t)
		{
			cnt += selfPow(2, 2 * n - 2);
			c -= selfPow(2, n - 1);
		}

		else if (c <= t && r > t)
		{
			cnt += selfPow(2, 2 * n - 2) * 2;
			r -= selfPow(2, n - 1);
		}

		else if (c > t && r > t)
		{
			cnt += selfPow(2, 2 * n - 2) * 3;
			r -= selfPow(2, n - 1);
			c -= selfPow(2, n - 1);
		}

		n--;
	}
	
	cnt += (r - 1) * 2 + c;
	cnt--;

	cout << cnt << endl;
	return 0;
}

int selfPow(int a, int b)
{
	if (b == 0)
		return a;

	int t = 1;
	
	for (int i = 0; i < b; i++)
		t *= a;

	return t;
}