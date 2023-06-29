#include <string>
#include <vector>
#include <regex>
using namespace std;

bool isRightString(string s) {
    bool answer;
    int newSize = s.length() - 1;
    while (s.length() > 0 && (s.length() != newSize)) {
        newSize = s.length();
        s = regex_replace(s, regex("\\{\\}"), "");
        s = regex_replace(s, regex("\\[\\]"), "");
        s = regex_replace(s, regex("\\(\\)"), "");
    }
    if (s.length() == 0) { answer = true; }
    else { answer = false; }
    return answer;
}

int solution(string s) {
    int answer = 0;
    string answerString = s;
  
    if (s.length() % 2 != 0) { return 0; } // 홀수면 오답

    for (auto& character : answerString) {
        if (isRightString(s)) {
            answer++;
        }
        s.erase(s.begin());
        s += character;
    }
    return answer;
}
