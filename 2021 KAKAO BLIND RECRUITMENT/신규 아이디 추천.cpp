#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    bool successive = false;
    bool checkStart = false;
    bool checkEnd = false;
    vector<char> v;
    vector<char> v2;
    for (int i = 0; i < new_id.size(); i++)
    {
        /////////////1
        if (new_id[i] >= 65 && new_id[i] <= 90)
            new_id[i] += 32;
        ////////////2
        else if ((new_id[i] < 48 || new_id[i] > 57) && (new_id[i] < 97 || new_id[i] > 122) && new_id[i] != '-' &&
            new_id[i] != '_' && new_id[i] != '.')
            new_id[i] = '!';
        ////////////3
        if (new_id[i] != '.' && new_id[i] != '!')
            successive = false;

        else if (new_id[i] == '.' && successive)
            new_id[i] = '!';

        else if (new_id[i] == '.' && !successive)
            successive = true;
        ////////////4
        if (!checkStart)
        {
            if (new_id[i] == '.')
                new_id[i] = '!';
            else
                checkStart = true;
        }
    }

    for (int i = new_id.size() - 1; i >= 0; i--)
    {
        if (!checkEnd)
        {
            if (new_id[i] == '.')
                new_id[i] = '!';
            else
                checkEnd = true;
        }
    }
    ///////////////////////
    int n = 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.')
            n++;
    }
    ///////////////////////
    ////////////5
    if ((new_id.size() - n) == 0)
        new_id = 'a';

    //cout << new_id << endl;

    ////////////6
    string ss = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] != '!')
            ss += new_id[i];
    }

    //cout << ss << endl;

    int cnt = 0;
    for (int i = 0; i < ss.size(); i++)
    {
        if (cnt < 15)
        {
            if ((cnt == 0 && ss[i] == '.') || ((cnt == 14 || i == (ss.size() - 1)) && ss[i] == '.'))
            {
                if ((cnt == 14 || i == (ss.size() - 1)) && ss[i] == '.')
                  cnt++;
            }

            else
            {
                v.push_back(ss[i]);
                cnt++;
            }
        }
    }

    if (v.size() == 0)
        v.push_back('a');

     /* for (int i = 0; i < v.size(); i++)
          cout << v[i];
      cout << endl;*/

      ////////////7
    if (v.size() < 3)
    {
        char c = v[v.size() - 1];
       // cout << c << endl;
        while (v.size() < 3)
        {
            v.push_back(c);
        }
    }
    /* for (int i = 0; i < v.size(); i++)
         cout << v[i];
     cout << endl;*/
     ////////////
    string answer = "";
    for (int i = 0; i < v.size(); i++)
    {
        answer += v[i];
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;

    s = solution(s);
    cout << s << endl;

    return 0;
}