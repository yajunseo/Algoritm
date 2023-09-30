#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFirst = true

    for (auto c : s)
    {
        cout << c << endl;
        char t = c;

        if (!isdigit(t))
        {
            if (isFirst)
            {
                t = toupper(c);
            }
        }

        answer += t;


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