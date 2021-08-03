#include <iostream>

using namespace std;
int n;
int arr[6] = { 500,100,50,10,5,1 };

int greedy(int num)
{
    int cnt = 0;
    int r = 1000 - num;
    for (int i = 0; i < 6; i++)
    {
        int t = r / arr[i];
        cnt += t;
        
        r -= arr[i] * t;
    }
    return cnt;
}

int main() {
    cin >> n;
    cout << greedy(n);
    return 0;
}