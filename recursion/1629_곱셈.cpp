#include <iostream>

using namespace std;

long long pow(long long a, long long b, long long c)
{
	if (b == 1) return a % c;
	long long p = pow(a, b / 2, c);
	p = p * p % c;

	if (b % 2 == 0)
		return p;


	return p * a % c;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c) << endl;
}

