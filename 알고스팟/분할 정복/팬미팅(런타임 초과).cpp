#include <iostream>
#include <string>
#include <vector>
#define min(a, b) a<b? a:b
using namespace std;


vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	if (a.size() == 0 || b.size() == 0)
	{
		return vector<int>();
	}

	vector<int> c(a.size() + b.size() - 1, 0);

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	return c;
}

void addto(vector<int>& a, const vector<int>& b, int k)
{
	vector<int> c(b);
	c.insert(c.begin(), k, 0);
	if (c.size() > a.size())
	{
		for (int i = 0; i < a.size(); i++) { c[i] += a[i]; }
		a.swap(c);
		return;
	}

	if (c.size() <= a.size())
	{
		for (int i = 0; i < c.size(); i++) { a[i] += c[i]; }
	}
	c.clear();
}

void subfrom(vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < b.size(); i++)
	{
		a[i] -= b[i];
	}
}


vector<int> kara(const vector<int>& a, const vector<int>& b)
{
	int a_size = a.size(), b_size = b.size();
	if (a_size < b_size) { return kara(b, a); }
	if (a_size <= 50) { return multiply(a, b); };

	int half = min(a_size, b_size) / 2;
	vector<int>a0(a.begin(), a.begin() + half);
	vector<int>a1(a.begin() + half, a.end());
	vector<int>b0(b.begin(), b.begin() + half);
	vector<int>b1(b.begin() + half, b.end());
	vector<int>z2 = kara(a1, b1);
	vector<int>z0 = kara(a0, b0);
	addto(a0, a1, 0);
	addto(b0, b1, 0);
	vector<int>z1 = kara(a0, b0);
	subfrom(z1, z0);
	subfrom(z1, z2);
	vector<int> ret;
	addto(ret, z0, 0);
	addto(ret, z1, half);
	addto(ret, z2, half * 2);
	return ret;
}


int fanMeeting(const string& s1, const string& s2)
{
	int size1 = s1.size();
	int size2 = s2.size();
	
	int hug = 0;

	vector<int> v1(size1), v2(size2);

	for (int i = 0; i < size1; i++)
		v1[i] = (s1[i] == 'M');

	for (int i = 0; i < size2; i++)
		v2[size2 - i - 1] = (s2[i] == 'M');

	vector<int> result = kara(v1, v2);
	for (int i = v1.size() - 1; i < v2.size(); i++)
	{
		if (result[i] == 0)
			hug++;
	}
	return hug;
}

int main()
{
	int c;
	string s1, s2;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> s1;
		cin >> s2;
		
		cout << fanMeeting(s1, s2) << endl;
	}
	return 0;
}

