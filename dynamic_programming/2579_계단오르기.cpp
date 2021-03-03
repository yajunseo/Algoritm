#include <iostream>
#include <list>
#include <vector>
#include <queue>

#define MaxNum(a,b) a>b? a:b
using namespace std;

int n;
int arr[301] = { 0, };
int maxArr[301] = { 0, };

void findRoot();

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
		cout << arr[n] << endl;

	else if (n == 2)
		cout << arr[1] + arr[2] << endl;

	else if (n == 3)
	{
		int max = MaxNum(arr[1] + arr[3], arr[2] + arr[3]);
		cout << max << endl;
	}

	else
	{
		findRoot();
		cout << maxArr[n] << endl;
	}

	return 0;
}

void findRoot()
{
	maxArr[1] = arr[1];
	maxArr[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		int a = MaxNum(maxArr[i - 3] + arr[i - 1], maxArr[i - 2]);
		maxArr[i] = arr[i] + (MaxNum(maxArr[i - 3] + arr[i - 1], maxArr[i - 2]));
	}
}
