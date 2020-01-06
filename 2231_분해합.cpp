#include <iostream>
using namespace std;

typedef struct Person
{
	int weight;
	int height;
}person;

int ranking(person* arr, int size, int n)
{
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (i != n)
			if (arr[n].weight < arr[i].weight && arr[n].height < arr[i].height)
				count++;
	}
	return count;
}

void printArray(int* rank, int size)
{
	for (int i = 0; i < size; i++)
		cout << rank[i] << " ";
}

int main()
{
	int num;
	cin >> num;

	person* p = (person*)malloc(sizeof(person) * num);
	for (int i = 0; i < num; i++)
		cin >> p[i].weight >> p[i].height;
	
	int* rank = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
		rank[i] = ranking(p, num, i);

	printArray(rank, num);

	return 0;
}