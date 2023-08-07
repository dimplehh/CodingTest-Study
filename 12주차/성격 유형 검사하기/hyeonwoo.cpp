#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

    map<char, int> score_dict; // 문자당 점수 담는 딕셔너리
    string answer = "";

    for (int i = 0;i < survey.size();i++) {
        // 점수 담기
        switch (choices[i]) {
        case 1:
            score_dict[survey[i][0]] += 3;
            break;
        case 2:
            score_dict[survey[i][0]] += 2;
            break;
        case 3:
            score_dict[survey[i][0]] += 1;
            break;
        case 5:
            score_dict[survey[i][1]] += 1;
            break;
        case 6:
            score_dict[survey[i][1]] += 2;
            break;
        case 7:
            score_dict[survey[i][1]] += 3;
            break;
        }
    }

    // 1번문항
    if (score_dict['R'] == score_dict['T']) answer += 'R';
    else (score_dict['R'] > score_dict['T']) ? answer += 'R' : answer += 'T';
    // 2번문항
    if (score_dict['C'] == score_dict['F']) answer += 'C';
    else (score_dict['C'] > score_dict['F']) ? answer += 'C' : answer += 'F';
    // 3번문항
    if (score_dict['J'] == score_dict['M']) answer += 'J';
    else (score_dict['J'] > score_dict['M']) ? answer += 'J' : answer += 'M';
    // 4번문항
    if (score_dict['A'] == score_dict['N']) answer += 'A';
    else (score_dict['A'] > score_dict['N']) ? answer += 'A' : answer += 'N';

    return answer;
}