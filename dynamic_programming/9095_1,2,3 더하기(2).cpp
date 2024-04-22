#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[15];

	for (int i = 0; i < n; i++)
	{
		int test;
		cin >> test;


		fill_n(arr, 15, 0);
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;

		if (test > 3)
		{
			for (int j = 4; j <= test; j++)
			{
				arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
			}
		}

		cout << arr[test] << endl;
	}
}

