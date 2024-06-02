#include <iostream>
#include <list>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main() {
	int n;
	cin >> n;

	list<int> listA;
	list<int> listB;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		listA.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		listB.push_back(num);
	}

	listA.sort();
	listB.sort(compare);

	int answer = 0;

	auto itA = listA.begin();
	auto itB = listB.begin();

	while (itA != listA.end() && itB != listB.end())
	{
		answer += ((*itA) * (*itB));
		itA++;
		itB++;
	}

	cout << answer << endl;
}

