#include <iostream>
#include <vector>

using namespace std;


int solution(vector<int> number) {
    int count = 0;

    for (int i = 0; i < number.size() - 2; i++)
    {
        for (int j = i + 1; j < number.size() - 1; j++)
        {
            for (int r = j + 1; r < number.size(); r++)
            {
                if (number[i] + number[j] + number[r] == 0)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    vector<int> v{-2, 3, 0, 2, -5};
    cout << solution(v);
}