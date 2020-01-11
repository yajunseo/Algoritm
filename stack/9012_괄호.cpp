#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

bool check(string s, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (st.empty() && s[i] == ')')
			return false;
		else if (s[i] == '(')
			st.push('(');
		else
			st.pop();
	}
	if (st.empty())
		return true;
	else
		return false;
}

void stack_init()
{
	while (!st.empty())
	{
		st.pop();
	}
}

int main()
{
	int n;
	int length;
	bool checking;
	cin >> n;
	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		length = str.length();
		checking = check(str, length);
		if (checking)
			cout << "YES"<<endl;
		else
			cout << "NO"<<endl;
		stack_init();
	}
	
	return 0;
}