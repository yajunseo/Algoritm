#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;


void insertTable(int *arr)
{
	int startTable = -1;
	int endTable = -1;
	int farstartTable = -1;
	int farendTable = -1;
	int far = 0;
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			temp++;
			if (startTable == -1)
				startTable = i;
			else
				endTable = i;
		}

		else
		{
			if (far < temp)
			{
				far = temp;
				farstartTable = startTable;
				farendTable = endTable;
			}
			temp = 0;
			startTable = -1;
		}
	}

	if (farstartTable == -1)
	{
		if(arr[0]== 0)
			arr[0] = 1;
		else
			arr[n - 1] = 1;
		return;
	}
	arr[(farendTable + farstartTable) / 2] = 1;
}

int getLength(int* arr)
{
	int startTable = -1;
	int endTable = 0;
	int farstartTable = -1;
	int farendTable = 0;
	int far = 0;
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			temp++;
			if (startTable == -1)
				startTable = i;
			else
				endTable = i;
		}

		else
		{
			if (far < temp)
			{
				far = temp;
				farstartTable = startTable;
				farendTable = endTable;
			}
			temp = 0;
			startTable = -1;
		}
	}

	return far;
}

int main()
{
	cin >> n;
	int *arr = new int[n];
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		arr[i] = s[i] - '0';
	}

	insertTable(arr);

	insertTable(arr);

	cout << getLength(arr) << endl;
	return 0;
}