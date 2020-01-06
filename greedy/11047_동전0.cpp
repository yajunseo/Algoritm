#include <iostream>
using namespace std;

int minCoin(int* arr, int size, int money)
{
	int count = 0;
	int n = size - 1;
	while (n >= 0)
	{
		if (arr[n] <= money)
		{
			count++;
			money -= arr[n];
		}
		else
			n--;

		if (money <= 0)
			break;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	int* coin = (int*)malloc(sizeof(int) * n);
	int money;
	cin >> money;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}


	cout << minCoin(coin, n, money);

	return 0;
}