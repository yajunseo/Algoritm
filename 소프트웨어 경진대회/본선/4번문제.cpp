#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int maxstudent = 0;

int arr[1001][2] = { 0, }; // 학생유무, 감염 유무
int n;
int countstudent = 0;

int findRange(int num)
{
	int cnt1 = 0, cnt2 = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		cnt1++;
		if (arr[i][1] == 1)
			break;
	}

	for (int i = num + 1; i <= maxstudent; i++)
	{
		cnt2++;
		if (arr[i][1] == 1)
			break;
	}

	return (cnt1 < cnt2) ? cnt1 : cnt2;
}

void deleteVirus(int num)
{
	for (int i = num; i <= num + 3; i++)
	{
		if (i >= 0 && i <= maxstudent)
		{
			if (arr[i][1] = 0);
		}
	}

	//for (int i = num; i >= num - 3; i--)
	//{
	//	if (i >= 0 && i <= maxstudent)
	//	{
	//		if (arr[i][1] = 0);
	//	}
	//}
}

int main()
{
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (maxstudent < a)
			maxstudent = a;

		arr[a][0] = 1;
		if(b== 1)
			arr[a][1] = 1;
		else
			arr[a][1] = 0;
	}

	int range = 10000000;
	for (int i = 0; i <= maxstudent; i++)
	{
		int temp = 10000000;
		if (arr[i][0] == 1 && arr[i][1] == 0)
		{
			temp = findRange(i);
		}
		if (temp < range)
			range = temp;

	}

	for (int i = 0; i <= maxstudent; i++)
	{
		if (arr[i][0] == 1 && arr[i][1] == 1)
		{
			countstudent++;
			deleteVirus(i);
		}
	}

	cout << countstudent << endl;
	return 0;
}