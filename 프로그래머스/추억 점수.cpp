#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    unordered_map<string, int> m;

    for (int i = 0; i < name.size(); i++)
    {
        m[name[i]] = yearning[i];
    }

    for (vector<string> vec : photo)
    {
        int sum = 0;

        for (string s : vec)
        {
            if (m.find(s) != m.end())
            {
                sum += m[s];
            }
        }

        answer.push_back(sum);
    }

    return answer;
}

int main()
{
   //test
}