#include <iostream>
using namespace std;

int map[128][128];
int white = 0;
int blue = 0;

void divide(int xs, int ys, int xe, int ye)
{
	int temp = map[xs][ys];
	
	for (int i = xs; i < xe; i++)
		for (int j = ys; j < ye; j++)
			if (temp != map[i][j])
			{
				divide(xs,ys,(xs+xe)/2,(ys+ye)/2);
				divide((xs+xe)/2,(ys+ye)/2,xe,ye);
				divide(xs,(ys+ye)/2,(xs+xe)/2,ye);
				divide((xs+xe)/2,ys,xe,(ys+ye)/2);
				return;
			}

	if (temp)
		blue++;
	else
		white++;
	return;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	divide(0, 0, n, n);

	cout << white << endl << blue;
	return 0;
}