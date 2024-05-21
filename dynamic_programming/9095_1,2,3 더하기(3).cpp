#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* numArr = new int[n];
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> numArr[i];

		if (max < numArr[i])
			max = numArr[i];
	}

	int* answer = new int[11];
	answer[0] = 1;
	answer[1] = 2;
	answer[2] = 4;

	for (int i = 3; i < max; i++)
	{
		answer[i] = answer[i - 1] + answer[i - 2] + answer[i - 3];
	}

	for (int i = 0; i < n; i++)
	{
		cout <<answer[numArr[i] - 1] << endl;
	}
}

