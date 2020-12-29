#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
	cin >> n >> m;

	if (n == 1)
		cout << "1" << endl;

	else if (n == 2)
	{
		if (m >= 9)
			cout << "4" << endl;
		else
			cout << (m + 1) / 2 << endl;
	}

	else
	{
		if (m <= 6)
		{
			if (m <= 4)
				cout << m << endl;
			else
				cout << "4" << endl;
		}

		else
		{
			cout << 4 + (m - 6) << endl;
		}
	}

	return 0;
}
