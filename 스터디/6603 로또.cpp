#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[12] = { 0, };
int isPrint[12] = { 0, };

void initData()
{
	for (int i = 0; i < 12; i++)
	{
		arr[i] = 0;
		isPrint[i] = 0;
	}
}

void showLotto(int base, int count)
{
	if (count == 6)
	{
		for (int i = 0; i < n; i++)
		{
			if (isPrint[i] == 1)
				cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	if (n - base < 6 - count)
		return;

	isPrint[base] = 1;
	showLotto(base + 1, count + 1);

	isPrint[base] = 0;
	showLotto(base + 1, count);
}

int main()
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		initData();

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}


		showLotto(0, 0);
		cout << endl;
	}

	return 0;
}