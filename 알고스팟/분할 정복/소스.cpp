#include <iostream>
#include <string>
#define max(a, b) a>b? a:b
#define min(a, b) a<b? a:b

using namespace std;

int arr[20001] = {0,};

int fence(int left, int right)
{
	if (left == right)
	{
		return arr[left];
	}

	int maxPart = 0;
	int mid = (left + right) / 2;
	int lpart = fence(left, mid);
	int rpart = fence(mid + 1, right);
	maxPart = max(lpart, rpart);
	int loverlap = mid;
	int roverlap = mid + 1;

	int heigth = min(arr[loverlap], arr[roverlap]);

	maxPart = max(maxPart, heigth * 2);

	while (left < loverlap || roverlap < right)
	{
		if (roverlap < right && (left == loverlap || arr[loverlap - 1] < arr[roverlap + 1]))
		{
			roverlap++;
			heigth = min(heigth, arr[roverlap]);
		}

		else
		{
			loverlap--;
			heigth = min(heigth, arr[loverlap]);
		}
		maxPart = max(maxPart, (roverlap - loverlap + 1) * heigth);
	}

	return maxPart;
}

int main()
{
	int c, num, h;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			cin >> h;
			arr[j] = h;
		}

		cout << fence(0, num - 1) << endl;
	}
}