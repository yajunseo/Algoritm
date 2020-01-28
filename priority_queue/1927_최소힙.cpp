#pragma warning (disable: 4996)
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> arr;


	
	int m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		if (!m)
		{
			if (arr.empty())
				printf("0\n");
			else
			{
				printf("%d\n", arr.top());
				arr.pop();
			}
		}

		else
			arr.push(m);
	}
	return 0;
}