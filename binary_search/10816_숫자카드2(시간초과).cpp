#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	multiset<int> s;
	int n;
	int num;
	int m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s.insert(num);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num);
		printf("%d\n", s.count(num));
	}
	return 0;
}