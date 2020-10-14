#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10][1000] = { 0, };
int cnt[10] = { 0, };
bool isCorrect[10] = {0,};
int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> num(n, 0);
	vector<int> vec(n, 0);
	int correctCnt = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}



	for (int i = 0; i < n; i++)
	{
		num[i] = i + 1;
	}
	int temp = 0;
	int c = 0;
	while (c < k)
	{
		do {
			
			if (isCorrect[c])
			{
				temp = 0;
				for (int i = 0; i < n; i++)
				{
					if (num[i] == i + 1)
						temp++;
				}
				if (temp == n)
				{
					cout << endl;
					c++;
					break;
				}

				for (int i = 0; i < n; i++)
					cout << num[i] << " ";
				cout << endl;
				c++;
				break;
			}
		


			for (int j = 0; j < n; j++)
			{
				if (num[j] == arr[c][j])
				{
					cnt[c]++;
				}
			}
			if (cnt[c] == n)
				isCorrect[c] = true;
			else
				cnt[c] = 0;


		} while (next_permutation(num.begin(), num.end()));

	}
	return 0;
}