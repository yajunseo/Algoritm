#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Time
{
	int start;
	int end;
}time_table;


typedef int comp_f(const void*, const void*);
int compare(const time_table* a, time_table * b)
{
	int num1 = a->end;
	int num2 = b->end;

	if (num1 > num2)
		return 1;
	
	else if (num1 < num2)
		return -1;
	else if (num1 = num2)
		return a->start >= b->start ? 1 : -1;
	else
		return 0;
}

int count_council(time_table* arr, int num)
{
	int count = 0;
	int end_time = 0;


	for (int i = 0; i < num; i++)
	{
		if (end_time <= arr[i].start)
		{
			end_time = arr[i].end;
			count++;
		}
	}

	return count;
}

int main()
{
	int num;
	int size;
	cin >> num;
	time_table* arr = (time_table*)malloc(sizeof(time_table) * num);
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i].start >> arr[i].end;
	}
	qsort(arr, num, sizeof(time_table), (comp_f *)compare);

	cout << count_council(arr, num);
	return 0;
}