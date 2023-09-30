#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFirst = true;

    for (auto c : s)
    {
        if (!isdigit(c))
        {
            if (isFirst)
            {
                answer += toupper(c);
            }
            else
            {
                answer += tolower(c);
            }
        }

        else
        {
            answer += c;
        }

        if (c == ' ')
        {
            isFirst = true;
        }

        else
        {
            isFirst = false;
        }
    }

    return answer;
}

int main()
{
   //test
   cout << solution("3people unFollowed me");
}