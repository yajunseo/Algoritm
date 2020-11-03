#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
using namespace std;
int n;

void devideStarPrint(int num1, int num2)
{
	int temp1 = 0;
	int temp2 = 0;
	for (int i = n; i >= 3; i /= 3)
	{
		temp1 = num1 % i;
		temp2 = num2 % i;
		if (i / 3 <= temp1 && temp1 <= (i / 3 * 2 - 1) &&
			i / 3 <= temp2 && temp2 <= (i / 3 * 2 - 1))
		{
			cout << " ";
			return;
		}

	}
	if (num1 % 3 == 1 && num2 % 3 == 1)
		cout << " ";
	else
		cout << "*";
}


void printStar()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			devideStarPrint(i, j);
		}
		cout << endl;
	}

}

int main()
{
	cin >> n;
	printStar();
	
	return 0;
}