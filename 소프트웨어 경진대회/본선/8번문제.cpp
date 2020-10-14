#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;

//struct a
//{
//	int cArr[4] = {0,};
//};
int arr[1000][1000] = { 0, };
int m, n;
unsigned int c;
int a;
vector<int> v;
int ter(int r1, int c1, int r2, int c2)
{
	int sum = 0;
	for (int i = r1 - 1; i <= r2 - 1; i++)
	{
		for(int j= c1-1;j<=c2-1;j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> c;
	for (unsigned int i = 0; i < c; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a;
			v.push_back(a);
		}
	}

	
	for (int j = 0; j < v.size(); j += 4)
	{
		cout << ter(v[j], v[j + 1], v[j + 2], v[j + 3]) << endl;
	}


	return 0;
}