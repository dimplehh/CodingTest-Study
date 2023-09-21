#include <string>
#include <vector>


using namespace std;

string solution(string new_id) {
    string answer = "";
    answer = new_id;
    int cnt = 0;
    //1단계
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] >= 'A' && answer[i] <= 'Z') {
            answer[i] += 32;
        }
    }
    //2단계
    for (int i = 0; i < answer.length();) {
        if (!islower(answer[i]) && !isdigit(answer[i]) && answer[i] != '-' && answer[i] != '_' && answer[i] != '.') {
            answer.erase(i, 1);
        }
        else {
            i++;
        }
    }
    //3단계
    for (int i = 1; i < answer.length();) {
        if (answer[i] == '.' && answer[i - 1] == '.') {
            answer.erase(i, 1);
        }
        else {
            i++;
        }
    }
    //4단계
    if (!answer.empty() && answer[0] == '.') answer.erase(0, 1);
    if (!answer.empty() && answer.back() == '.') answer.pop_back();

    //5단계
    if (answer.empty()) answer = "a";

    //6단계
    if (answer.length() >= 16) {
        answer = answer.substr(0, 15);
        while (answer.back() == '.') {
            answer.pop_back();
        }
    }
    //7단계
    while (answer.length() <= 2) {
        answer += answer.back();
    }
    return answer;
}