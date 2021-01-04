#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
int n;
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		v[i] = v[i] * (n - i);
	}

	cout << *max_element(v.begin(), v.end()) << endl;



	return 0;
}
