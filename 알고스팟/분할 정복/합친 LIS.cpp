#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[101][101];
int arr1[101];
int arr2[101];
int n1, n2;

int Jlis(int a, int b)
{
	int& ret = cache[a + 1][b + 1];
	if (ret != -1) return ret;
	ret = 0;

	long long num1 = a == -1 ? -999999 : arr1[a];
	long long num2 = b == -1 ? -999999 : arr2[b];
	long long maxElemet = max(num1, num2);

	for (int i = a + 1; i < n1; i++)
	{
		if (maxElemet < arr1[i]) ret = max(ret, Jlis(i, b) + 1);
	}

	for (int i = b + 1; i < n2; i++)
	{
		if (maxElemet < arr2[i]) ret = max(ret, Jlis(a, i) + 1);
	}

	return ret;
}

int main()
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n1 >> n2;

		for (int j = 0; j < n1; j++)
			cin >> arr1[j];
		for (int j = 0; j < n2; j++)
			cin >> arr2[j];

		cout << Jlis(-1, -1) << endl;
	}
	return 0;
}

