#include <iostream>
#include <list>
#include <vector>
#include <queue>

#define maxWine(a,b) a>b?a:b

using namespace std;

int n;
int arr[10001] = { 0, };
int wine[10001] = { 0, };

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	wine[1] = arr[1];

	if (n >= 2)
		wine[2] = arr[1] + arr[2];

	if (n >= 3)
		wine[3] = arr[3] + (maxWine(arr[2] + wine[0], wine[1]));

	if (n >= 4)
	{
		for (int i = 4; i <= n; i++)
		{
			int maxNum = maxWine(arr[i - 1] + wine[i - 3], wine[i - 2]);
			maxNum = maxWine(maxNum, arr[i - 1] + wine[i - 4]);
			wine[i] = arr[i] + maxNum;
		}
	}

	//cout << "-----------------" << endl;
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << wine[i] << endl;
	//}
	//cout << "-----------------" << endl;

	int maxNum = maxWine(wine[n], wine[n - 1]);
	cout << maxNum << endl;

	return 0;
}
