#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
int n;


int main()
{
	cin >> n;
	int fiveBag = n / 5;
	int threeBag = 0;
	while (fiveBag >= 0)
	{
		int temp = n - fiveBag * 5;
		if (temp % 3 == 0)
		{
			threeBag = temp / 3;
			break;
		}
		fiveBag--;
	}

	if (fiveBag < 0)
		cout << "-1" << endl;

	else
		cout << fiveBag + threeBag << endl;

	return 0;
}
