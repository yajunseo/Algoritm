#include <iostream>
using namespace std;

int main()
{
	int n;
 	cin >> n;

	int arr[10000];
	arr[0] = 666;
	int cnt = 1;
	int number = 666;
	int temp, check;

	if (n > 1)
	{
		while (cnt < n)
		{
			number++;
			temp = number;
			check = 0;
			while (temp>0)
			{
				if (temp % 10 == 6)
				{
					check++;
					if (check == 3)
						break;
				}
				else
					check = 0;
				temp = temp / 10;
			}
			if (check == 3)
			{
				arr[cnt] = number;
				cnt++;
			}
		}
	}

	cout << arr[n - 1];
	return 0;
}