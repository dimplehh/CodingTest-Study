#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string target;
    string temp;
    bool answerFlag;

    int babbling_cnt = babbling.size();

    while (babbling_cnt--) {
        target = babbling.back();
        babbling.pop_back();
        int i = 0;
        answerFlag = true;
        temp = "";

        while (i < target.size()) {
            if (target.substr(i, 3) == "aya" && temp != "aya") { temp = "aya"; i += 3; }
            else if (target.substr(i, 2) == "ye" && temp != "ye") { temp = "ye"; i += 2; }
            else if (target.substr(i, 3) == "woo" && temp != "woo") { temp = "woo"; i += 3; }
            else if (target.substr(i, 2) == "ma" && temp != "ma") { temp = "ma"; i += 2; }
            else { answerFlag = false; break; }
        }

        if (answerFlag) answer++;
    }

    return answer;
}