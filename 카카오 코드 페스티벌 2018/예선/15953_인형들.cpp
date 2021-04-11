#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k;
int arr[500] = { 0, };
vector<long double> v;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];



	while (k <= n)
	{
		for (int i = 0; i <= n - k; i++)
		{
			long double sum = 0;
			long double avg = 0;
			long double disperse = 0;
			for (int j = i; j < i + k; j++)
			{
				sum += arr[j];
			}
			avg = (long double)sum / k;
			sum = 0;
			for (int j = i; j < i + k; j++)
			{
				sum += (long double)(arr[j] - avg) * (arr[j] - avg);
			}
			disperse = (long double)sum / k;
			disperse = sqrt(disperse);
			v.push_back(disperse);
		}
		k++;
	}
	sort(v.begin(), v.end());
	printf("%.11LF", v[0]);

	return 0;
}
