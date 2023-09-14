#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    int cnt = 1;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < index; j++) {
            cnt = 1;
            while (1) {
                if (s[i] + cnt > 'z') {
                    cnt -= 26;
                }
                if (skip.find(s[i] + cnt) == string::npos) {
                    break;
                }
                cnt++;
            }
            s[i] += cnt;
        }
    }
    answer = s;
    return answer;
}