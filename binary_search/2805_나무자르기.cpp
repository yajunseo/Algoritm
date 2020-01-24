#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	long long start, middle, end;
	start = 1;
	end = arr[n - 1];

	long long cut_tree = 0;
	long long temp = 0;
	bool check = false;
	while (start <= end && start>=1 && end >= 1)
	{
		middle = (start + end) / 2;
		temp = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] - middle > 0)
				temp += arr[i] - middle;
		}

		if (temp >= m)
		{
			start = middle + 1;
			
			if (cut_tree < middle)
			{
				cut_tree = middle;
				check = true;
			}
		}

		else
		{
			end = middle - 1;
			check = true;
		}
	}
	if (!check)
		cut_tree = arr[n - 1];
	printf("%lld", cut_tree);

	return 0;
}