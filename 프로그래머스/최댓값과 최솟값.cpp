#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

string solution(string s) {
    string answer = "";

    vector<string> result = split(s, ' ');

    int min = stoi(result[0]);
    int max = stoi(result[0]);

    for (int i = 0; i < result.size(); i++)
    {
        int num = stoi(result[i]);

        if (num < min)
        {
            min = num;
        }

        if (num > max)
        {
            max = num;
        }
    }

    answer = to_string(min) + " " + to_string(max);

    return answer;
}

int main()
{
   //test
   // Ä¿¹Ô Å×½ºÆ®
}