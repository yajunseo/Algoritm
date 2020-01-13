#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	bool check = true;

	while (1)
	{
		stack<char> st;
		getline(cin, str);
		if (str[0] == '.')
			return 0;
		
		if (str[0] == '.')
		{
			break;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);

			else if (str[i] == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					check = false;
					break;
				}
				else
					st.pop();
			}
			else if (str[i] == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					check = false;
				break;
				}
				else
					st.pop();
			}
		}
		if (st.empty() && check)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		check = true;
	}
	return 0;
}