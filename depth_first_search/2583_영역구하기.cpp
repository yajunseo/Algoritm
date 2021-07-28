#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
int arr[100][100] = { 0, };
int cnt = 0;
vector<int> v;

void dfs(int a, int b)
{
    if (arr[a][b] == 1)
        return;
    if (a > m - 1 || b > n - 1)
        return;

    if (a < 0|| b < 0)
        return;

    arr[a][b] = 1;
    cnt++;
    dfs(a + 1, b);
    dfs(a, b + 1);
    dfs(a - 1, b);
    dfs(a, b - 1);
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = b; i < d; i++)
            for (int j = a; j < c; j++)
                arr[i][j] = 1;

    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }

    sort(v.begin(), v.end());
    cout << v.size() << endl;

    for (auto vv : v)
        cout << vv << " ";

    return 0;
}