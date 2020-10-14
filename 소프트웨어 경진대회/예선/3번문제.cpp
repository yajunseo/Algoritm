#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int arr[100][100] = { 0, };
int m, n;
int cnt = 0;
int c = 0;
void findPath(int x, int y)
{

	if (arr[x][y] == 1 || x >m-1 || y>n-1)
		return;

	else if(arr[x][y] == 2)
	{
		cnt++;
		return;
	}


	findPath(x + 1, y);
	findPath(x, y + 1);
}

int main()
{
	int p;
	int x, y;
	cin >> m >> n;
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
	}

	arr[m - 1][n - 1] = 2;

	findPath(0,0);
	cout << cnt % 1000000007 << endl;
	return 0;
}