#include <string>
#include <vector>

using namespace std;

int minFatigue[10] = { 0 }; // 최소피로도
int useFatigue[10] = { 0 }; // 소모피로도
bool isVisited[10] = { 0 }; // 방문여부
int answer = 0; // 정답

void dfs_find(int _cnt, int k, int _dungeonSize) {
    if (_cnt > answer) answer = _cnt;
    for (int i = 0;i < _dungeonSize;i++) {
        if (!isVisited[i] && k >= minFatigue[i]) {
            isVisited[i] = true;
            dfs_find(_cnt + 1, k - useFatigue[i], _dungeonSize);
            isVisited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int fatigue = k;

    for (int i = 0;i < dungeons.size();i++) {
        minFatigue[i] = dungeons[i][0];
        useFatigue[i] = dungeons[i][1];
    }
    dfs_find(0, k, dungeons.size());
    return answer;
}