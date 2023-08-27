#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<int, string> m1;
    map<string, int> m2;

    for (int i = 0; i < players.size(); i++)
    {
        m1[i] = players[i];
        m2[players[i]] = i;
    }

    for (string s : callings)
    {
        int rank = m2[s];
        string prevPerson = m1[rank - 1];

        m1[rank] = prevPerson;
        m1[rank - 1] = s;

        m2[prevPerson] = rank;
        m2[s] = rank - 1;
    }

    for (auto s : m1)
    {
        answer.push_back(s.second);
    }

    return answer;
}

int main()
{
   
}