#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
int n;

vector <int>* v;

int main()
{
	srand(time(NULL));
	int n;
	cout << "몇 개 구매하실 건가요? :";
	cin >> n;

	v = new vector<int>[n];

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		while (cnt < 6)
		{
			int num = rand() % 45 + 1;
			auto find_num = find(v[i].begin(), v[i].end(), num);
			if (find_num == v[i].end())
			{
				v[i].push_back(num);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		sort(v[i].begin(), v[i].end());
		cout << i + 1 << "번 : ";
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}
