#include <iostream>
using namespace std;

int blackJack(int a[], int num, int count)
{
	int max = 0;
	for (int i=0;i<count-2;i++)
		for (int j = i+1; j < count - 1; j++)
			for (int r = j + 1; r < count; r++)
			{
				int sum = a[i] + a[j] + a[r];
				if (sum <= num && sum > max)
					max = sum;
			}
	return max;
}

int main()
{
	int count, num;
	cin >> count >> num;
	int card[100];
	for (int i = 0; i < count; i++)
		cin >> card[i];

	cout << blackJack(card, num, count);

	return 0;
}