#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int* coin = (int*)malloc(sizeof(int) * n);
	int k;
	scanf("%d", &k);
	int* arr = (int*)malloc(sizeof(int) * (k+1));
	arr[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}
	for (int j = 0; j < k + 1; j++)
		arr[j] = 0;
	
	arr[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k + 1; j++)
		{
			if (j - coin[i] >= 0)
				arr[j] += arr[j - coin[i]];
		}

	printf("%d", arr[k]);
	return 0;
}