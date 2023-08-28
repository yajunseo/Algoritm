#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    map<int, int> m;

    for (int i : tangerine)
    {
        if (m.find(i) != m.end())
        {
            m[i]++;
        }

        else
        {
            m[i] = 1;
        }
    }

    vector<pair<int, int>> sortedVec(m.begin(), m.end());
    sort(sortedVec.begin(), sortedVec.end(), compare);

    int sum = 0;

    while (sum < k)
    {
        sum += sortedVec[answer].second;
        answer++;
    }

    return answer;
}

int main()
{
   //test
   // Ä¿¹Ô Å×½ºÆ®
}