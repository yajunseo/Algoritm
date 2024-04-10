#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include<algorithm>
#include <stack>
using namespace std;


int main() {
    while (true)
    {
        cin.tie(0);

        stack<char> s;
        bool result = true;
        string a;

        getline(cin, a);

        if (a == ".")
            return 0;

        for (auto c : a)
        {
            if (c == '.')
                break;

            if (c == '[' || c == '(')
            {
                s.push(c);
            }
            

            else if (c == ']' || c == ')')
            {
                if (s.empty())
                {
                    result = false;
                    break;
                }

                char t = s.top();
                s.pop();

                if (c == ']' && t != '[')
                {
                    result = false;
                    break;
                }

                if (c == ')' && t != '(')
                {
                    result = false;
                    break;
                }
            }
        }


        if (!s.empty())
        {
            result = false;
        }

        cout << (result ? "yes" : "no") << endl;;
    }
}