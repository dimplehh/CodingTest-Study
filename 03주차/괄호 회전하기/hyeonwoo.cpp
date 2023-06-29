#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isWrong = false;
    stack<char> st;
    for (int n = 0; n < s.size(); n++) {
        while (!st.empty())st.pop();
        isWrong = false;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '[':
            case '(':
            case '{':
                st.push(s[i]);
                break;
            case ']':
                if (st.empty()) isWrong = true;
                if (!st.empty() && st.top() == '[') st.pop();
                break;
            case ')':
                if (st.empty()) isWrong = true;
                if (!st.empty() && st.top() == '(') st.pop();
                break;
            case '}':
                if (st.empty()) isWrong = true;
                if (!st.empty() && st.top() == '{') st.pop();
                break;
            }
        }
        if (st.empty() && !isWrong) answer++;
        s = s.substr(1, s.size() - 1) + s[0];
    }
    return answer;
}
int main() {
    int answer = solution("}()(){");
    cout << answer;
}