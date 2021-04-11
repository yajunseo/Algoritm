#include <iostream>

using namespace std;

int n;

int test17(int a)
{
	if (a >= 1)
	{
		if (a <= 1)
			return 5000000;
		else if (a <= 3)
			return 3000000;
		else if (a <= 6)
			return 2000000;
		else if (a <= 10)
			return 500000;
		else if (a <= 15)
			return 300000;
		else if (a <= 21)
			return 100000;
		else
			return 0;
	}
	else
		return 0;
}

int test18(int a)
{
	if (a >= 1)
	{
		if (a <= 1)
			return 5120000;
		else if (a <= 3)
			return 2560000;
		else if (a <= 7)
			return 1280000;
		else if (a <= 15)
			return 640000;
		else if (a <= 31)
			return 320000;
		else
			return 0;
	}
	else
		return 0;
}


int main()
{
	cin >> n;
	int a, b;

	while (n > 0)
	{
		cin >> a >> b;
		int price = test17(a) + test18(b);
		cout << price << endl;
		n--;
	}

	return 0;
}
