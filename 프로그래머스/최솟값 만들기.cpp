#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include<algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int length = A.size();

    sort(A.begin(), A.end(), greater<int>());

    sort(B.begin(), B.end());

    for (int i = 0; i < length; i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}

int main()
{
   //test
   cout << solution("3people unFollowed me");
}