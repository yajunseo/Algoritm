#include <iostream>
#include <algorithm>
using namespace std;

void check(int arr[], int s, int e, int f)
{
	int middle = (s + e)/2;
	if (f == arr[middle])
	{
		printf("1\n");
		return;
	}

	if(s>e)
	{
		printf("0\n");
		return;
	}

	if (f > arr[middle])
		check(arr, middle + 1, e, f);

	else if (f < arr[middle])
		check(arr, s, middle - 1, f);
}


int main()
{
	int n;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(&arr[0], &arr[n]);
	
	int m;
	cin >> m;
	int* arr2 = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	for (int i = 0; i < m; i++)
		check(arr, 0, n-1, arr2[i]);

	return 0;
}