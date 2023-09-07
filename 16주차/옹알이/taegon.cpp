#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int pos = 0;
    int cnt = 0;
    vector<string> ba = { "aya", "ye", "woo", "ma" };
    for (int i = 0; i < babbling.size(); i++) {
        cnt = 0;
        for (int j = 0; j < ba.size(); j++) {
            pos = 0;
            while (babbling[i].find(ba[j], pos) != string::npos) {
                if (pos == 0 || babbling[i].find(ba[j], pos) != pos) {
                    cnt += ba[j].length();
                }
                pos = babbling[i].find(ba[j], pos) + ba[j].length();

            }
        }
        if (cnt == babbling[i].length() && babbling[i].find("maya") == string::npos)
            answer++;
    }

    return answer;
}