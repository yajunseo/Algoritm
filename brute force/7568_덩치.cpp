#include <iostream>
using namespace std;

int digit(int a)
{
	int cnt = 0;
	while (a >= 10)
	{
		a = a / 10;
		cnt++;
	}
	return cnt + 1;
}

int main()
{
	int num;
	cin >> num;
	int count = digit(num);
	int arr[10] = { 0, };
	int generator = num - count*9;
	int temp = generator;
	int sum = 0;

	for (int i = generator; i <= num; i++)
	{	
		temp = generator;
		for (int j = 0; j < count; j++)
		{
			arr[j] = temp % 10;
			temp = temp / 10;
		}

		for (int j = 0; j < count; j++)
		{
			sum += arr[j];
		}
		if (generator + sum == num)
		{
			cout << generator;
			return 0;
		}
		generator++;
		sum = 0;
	}
	cout << 0;
	return 0;
}