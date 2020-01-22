#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k, n;
    string input;
    long long middle, start, end;
    long long count = 0;
    cin >> k >> n;
    long long* arr = (long long*)malloc(sizeof(long) * k);

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + k);

    start = 1;
    end = arr[k - 1];
  
    long long temp = 0;
    while (start <= end)
    {
        middle = (start + end) / 2;
        for (int i = 0; i < k; i++)
        {
            temp += arr[i] / middle;
        }
        if (temp >= n)
        {
            count = middle;
            start = middle + 1;
        }

        else
        {
            end = middle - 1;
        }
        temp = 0;
    }
    printf("%d",count);

	return 0;
}