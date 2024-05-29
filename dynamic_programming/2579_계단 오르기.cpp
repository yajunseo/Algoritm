#include <iostream>

using namespace std;

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int** score = new int* [n];
	for (int i = 0; i < n; i++)
	{
		score[i] = new int[2];
	}

	if (n == 1)
	{
		cout << arr[0];
		return 0;
	}

	else if (n == 2)
	{
		cout << arr[0] + arr[1];
		return 0;
	}

	score[0][0] = 0;
	score[0][1] = arr[0];
	score[1][0] = arr[1];
	score[1][1] = arr[0] + arr[1];

	for (int i = 2; i < n; i++)
	{
		score[i][0] = GetMax(score[i - 2][0], score[i - 2][1]) + arr[i];
		score[i][1] = score[i - 1][0] + arr[i];
	}

	int max = GetMax(score[n - 1][0], score[n - 1][1]);
	cout << max;
	return 0;
}

