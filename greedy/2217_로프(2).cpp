#include <iostream>
#include <list>

using namespace std;


int main() {
	int n;

	cin >> n;

	list<int> list;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		list.push_back(num);
	}

	list.sort();

	auto it = list.begin();

	int index = 0;
	int max = 0;

	while (it != list.end())
	{
		int num = *it * (n - index);
		if (num > max)
			max = num;

		index++;
		it++;
	}

	cout << max << endl;
}

