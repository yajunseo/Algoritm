#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n, m;
	cin >> n;

	unordered_map<int, int> card;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		card[num]++;
	}

	cin >> m;
	int* arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		auto it = card.find(arr[i]);
		if (it == card.end())
			cout << "0 ";

		else
			cout << it->second << " ";
	}
}

