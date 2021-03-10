#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int n;
unsigned int arr[1001] = { 0, };

int main()
{
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}

	/*
	1
	1+1
	1+2
	1+3+1
	1+4+3
	1+5+6+1
	=> 1 2 3 5 8 13 
	*/
	printf("%d\n", arr[n]);

	return 0;
}
