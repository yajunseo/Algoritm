#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


struct Person {
    string code;
    string job;
    string career;
    string food;
    int score;
};
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Person> vPerson;

    for (auto i : info) {
        Person p;
        istringstream is(i);
        string score;
        is >> p.code >> p.job >> p.career >> p.food >> score;
        p.score = stoi(score);
        vPerson.push_back(p);
    }

    for (auto i : query) {
        Person p;
        istringstream is(i);
        string score;
        string dump;

        is >> p.code >> dump >> p.job >> dump >> p.career >> dump >>
            p.food >> score;
        p.score = stoi(score);



        int cnt = 0;
        for (auto j : vPerson) {
            if (j.code != p.code && p.code != "-")
                continue;
            if (j.job != p.job && p.job != "-")
                continue;
            if (j.career != p.career && p.career != "-")
                continue;
            if (j.food != p.food && p.food != "-")
                continue;
            if (j.score < p.score)
                continue;
            cnt++;
        }
        answer.push_back(cnt);
    }


    return answer;
}