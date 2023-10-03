#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isRight(string s) {
    stack<char> st;
    for (int i = 0;i < s.size();i++) {
        if (s[i] == '(') st.push(s[i]);
        else {
            if (st.empty()) return false;
            st.pop();

        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if (p == "") return ""; // 1. ºó ¹®ÀÚ¿­ÀÌ¸é ºó¹®ÀÚ¿­¹ÝÈ¯

    int leftCnt = 0, rightCnt = 0;
    string u, v;

    for (int i = 0;i < p.size();i++) {
        if (p[i] == '(') leftCnt++;
        else rightCnt++;
        if (leftCnt == rightCnt) {     // 2. ±ÕÇüÀâÈù °ýÈ£ ¹®ÀÚ¿­·Î ³ª´®
            u = p.substr(0, i + 1);
            v = p.substr(i);
            break;
        }
    }
    if (isRight(u)) {
        answer = u + solution(v);      // 3-1
    }
    else {
        answer = '(' + solution(u) + ')';      // 4-1, 4-3
        for (int j = 1;j < u.size();j++) answer += u[j] == ')' ? '(' : ')';     // 4-4
    }

    return answer;
}