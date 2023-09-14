#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> person;

    for (int i = 0; i < weights.size(); i++) {
        person[weights[i]]++;
    }

    for (auto i : person) {
        if (person.count(i.first * 2)) {
            answer += i.second * person[i.first * 2];
        }
        if (i.first * 3 % 2 == 0 && person.count(i.first * 3 / 2)) {
            answer += i.second * person[i.first * 3 / 2];
        }
        if (i.first * 4 % 3 == 0 && person.count(i.first * 4 / 3)) {
            answer += i.second * person[i.first * 4 / 3];
        }

        answer += i.second * (i.second - 1) / 2;
    }


    return answer;
}