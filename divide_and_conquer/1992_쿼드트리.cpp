#include <iostream>
using namespace std;
string map[64];

void divide(int xs, int xe, int ys, int ye)
{
	bool is_same = true;
	for(int i=ys;i<ye;i++)
		for (int j = xs; j < xe; j++)
		{
			if (map[i][j] != map[ys][xs])
			{
				is_same = false;
				break;
			}
		}

	if (is_same)
	{
		cout << map[ys][xs];
		return;
	}

	cout << "(";
	divide(xs, (xs + xe) / 2, ys, (ys + ye) / 2);
	divide((xs + xe)/2, xe, ys, (ys + ye) / 2);
	divide(xs, (xs + xe) / 2, (ys + ye) / 2, ye);
	divide((xs + xe)/2, xe, (ys + ye) / 2, ye);
	cout << ")";
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> map[i];

	divide(0, n, 0, n);
	return 0;
}