#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main()
{
	int n;
	int number;
	int sum = 0;
	int temp = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> number;
		if (number)
			st.push(number);
		else
			st.pop();
	}

	while (1)
	{
		if (st.empty())
			break;
		sum += st.top();
		st.pop();
	}
	
	cout << sum;
	return 0;
}