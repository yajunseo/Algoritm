#include <iostream>
#include <stdlib.h>
using namespace std;
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	
	if (num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;
	else
		return 0;
}

int main()
{
	int num;
	cin >> num;
	int sum = 0;
	int time = 0;
	int* arr = (int*)malloc(sizeof(int) * num);
	int* time_arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	qsort(arr, num, sizeof(arr[0]), compare);

	for (int i = 0; i < num; i++)
	{
		time += arr[i];
		time_arr[i] = time;
	}
	for (int i = 0; i < num; i++)
		sum += time_arr[i];

	cout << sum;
	return 0;
}