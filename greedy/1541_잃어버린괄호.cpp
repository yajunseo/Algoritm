#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string s;
	cin >> str;
	int strlen = str.length();
	int start = 0;
	int end = -1;
	int arr[50] = { 0, };
	int sign[50] = { 0, };
	int count = 0;
	int sum = 0;
	int flag = 0;

	for (int i = 0; i < strlen; i++)
	{
		if (str[i] == '-')
		{
			start = end + 1;
			end = i;
			s = str.substr(start, end);
			arr[count] = stoi(s);
			if (flag == 0)
			{
				sign[count] = 1;
				flag = 1;
			}
	
			count++;
		}
		if (str[i] == '+')
		{
			start = end + 1;
			end = i;
			s = str.substr(start, end);
			arr[count] = stoi(s);
			if (flag == 0)
				sign[count] = 1;
			count++;
		}
		else if (i == strlen - 1)
		{
			start = end + 1;
			end = i + 1;
			s = str.substr(start, end);
			arr[count] = stoi(s);
			if (flag == 0)
				sign[count] = 1;
			count++;
		}

	}


	sum = arr[0];
	if (count > 1)
	{
		for (int i = 1; i < count; i++)
		{
			if (sign[i] == 1)
				sum += arr[i];
			else
				sum -= arr[i];
		}
	}
	else
		sum -= arr[1];

	cout << sum;
	return 0;
}