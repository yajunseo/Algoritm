#include <iostream>
using namespace std;

long f[90] = { -1, };

long fibinacci(int n)
{
	f[1] = 1; f[2] = 1;
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
	}
	return f[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fibinacci(n) << endl;
	return 0;
}