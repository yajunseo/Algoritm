#include <string>
#include <vector>
#include <iostream>

using namespace std;
int sSize = 0;

int slice(string s, int n)
{

    int cnt = 0;
    bool IsFirst = true;
    string temp = "";
    string temp2 = "";
    bool same = false;
    for (int i = 0; i < sSize; i += n)
    {
        temp2 = s.substr(i, n);

        if (!same)
        {
            if (temp == temp2)
            {
                same = true;
            }
            else
            {
                if (!IsFirst)
                    cnt += n;
            }
        }

        else
        {
            if (temp != temp2)
            {
                same = false;
                cnt += (n + 1);
            }
        }
        temp = temp2;
        IsFirst = false;
    }

    if (sSize % n > 0)
        cnt += (sSize % n);

    else
    {
        if (!same)
            cnt += n;
        else
            cnt += (n + 1);
    }

    return cnt;
}

int solution(string s) {
    sSize = s.size();
    int n = sSize;
    for (int i = 1; i < sSize / 2 + 1; i++)
    {
        int temp = slice(s, i);
        if (n > temp)
            n = temp;
    }

    return n;
}