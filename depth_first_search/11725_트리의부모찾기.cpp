#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
void DFS(int k);

int n;

struct tree
{
	int par;
	vector<int> node;
}tree[100001];

int visit[100001] = { 0, };

int main()
{
	cin >> n;
	for (int i = 1; i <= n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].node.push_back(b);
		tree[b].node.push_back(a);
	}

	visit[1] = 1;
	DFS(1);
	for (int i = 2; i <= n; i++)
	{
		//cout << tree[i].par << endl;
		printf("%d\n", tree[i].par);
	}

	return 0;
}

void DFS(int k)
{
	for (int i = 0; i < tree[k].node.size(); i++)
	{
		if (visit[tree[k].node[i]])
		{
			tree[k].par = tree[k].node[i];
		}

		else
		{
			visit[tree[k].node[i]] = 1;
			DFS(tree[k].node[i]);
		}
	}
}
