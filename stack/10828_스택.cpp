#include <iostream>
using namespace std;

int stack[10000] = { 0, };
int top = 0;

void push(int a)
{
	stack[top] = a;
	top++;
}

int pop()
{
	int p;
	if (top - 1 >= 0)
	{
		p = stack[--top];
		return p;
	}
	else
		return -1;
}

int size()
{
	return top;
}

int empty()
{
	if (top == 0)
		return 1;
	else
		return 0;
}

int top_stack()
{
	if (top - 1 >= 0)
		return stack[top - 1];
	else
		return -1;
}

int main()
{
	int n;
	int number;
	cin >> n;
	
	string command;

	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> number;
			push(number);
		}
		else if (command == "pop")
			cout<<pop()<<endl;
		else if (command == "size")
			cout<<size()<<endl;
		else if (command == "empty")
			cout<<empty()<<endl;
		else if (command == "top")
			cout<<top_stack()<<endl;
	}
	return 0;
}