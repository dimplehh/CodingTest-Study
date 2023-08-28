#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> score;
    int size = survey.size();
    for (int i = 0; i < size; i++) {
        string s(survey[i]);
        if (choices[i] == 4)
            continue;
        else if (choices[i] < 4) {
            score[s[0]] += 4 - choices[i];
        }
        else {
            score[s[1]] += choices[i] - 4;
        }
    }

    answer += (score['R'] >= score['T']) ? 'R' : 'T';
    answer += (score['C'] >= score['F']) ? 'C' : 'F';
    answer += (score['J'] >= score['M']) ? 'J' : 'M';
    answer += (score['A'] >= score['N']) ? 'A' : 'N';
    return answer;
}
