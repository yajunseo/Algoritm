#include <iostream>
#include <cstring>
using namespace std;
int t;
int arr[12] = { 0, };

int dynamic(int num)
{
    if (num < 0)
        return 0;

    if (num <= 1)
        return 1;

    if (arr[num])
        return arr[num];

    return arr[num] = dynamic(num - 3) + dynamic(num - 2) + dynamic(num - 1);
}

int main() {
    cin >> t;

    while (t > 0)
    {
        int n;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        cin >> n;
        cout << dynamic(n) << endl;
        t--;
        memset(arr, 0, sizeof(arr));
    }

    return 0;
}