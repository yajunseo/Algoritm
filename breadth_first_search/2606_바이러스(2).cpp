#include <iostream>
#include <queue>

using namespace std;

int a, b;
int arr[101][101] = { 0, };
int check[101] = { 0, };
queue<int> q;
int cnt = -1;

void bfs(int num)
{
    q.push(num);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        cnt++;
        for (int i = 1; i <= a; i++)
        {
            if (i != n)
            {
                if (arr[n][i] == 1 && check[i] != 1)
                {
                    q.push(i);
                    check[i] = 1;
                }
            }
        }

    }
}

int main() {
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        arr[t1][t2] = 1;
        arr[t2][t1] = 1;
    }

    check[1] = 1;
    bfs(1);
    cout << cnt;

    return 0;
}