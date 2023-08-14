#include <string>
#include <vector>
#include <map>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 999

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> dict;

    // 해시 초기화
    for (char i = 'A';i <= 'Z';i++) dict[i] = INF;

    // 해시에 등록
    for (int i = 0;i < keymap.size();i++) {
        for (int j = 0;j < keymap[i].size();j++) {
            dict[keymap[i][j]] = MIN(dict[keymap[i][j]], j + 1);
        }
    }

    // 해시 탐색
    for (int i = 0;i < targets.size();i++) {
        int temp = 0;
        for (int j = 0;j < targets[i].size();j++) {
            if (dict[targets[i][j]] == INF) { temp = -1; break; }
            else temp += dict[targets[i][j]];
        }
        answer.push_back(temp);
    }
    return answer;
}