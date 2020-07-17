#include <iostream>
#include <string>
using namespace std;

string quad(string::iterator& it)
{
	char first = *it;

	it++;

	if (first == 'w' || first == 'b')
		return string(1, first);

	string ul = quad(it);
	string ur = quad(it);
	string ll = quad(it);
	string lr = quad(it);

	return "x" + ll + lr + ul + ur;
}

int main()
{
	int c;
	string s;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> s;
		auto it = s.begin();
		cout << quad(it) << endl;
	}

}