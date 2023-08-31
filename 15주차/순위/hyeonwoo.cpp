#include <string>
#include <vector>

using namespace std;

int players[101] = { 0, };
int graph[101][101] = { 0, };

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<int> correctPlayer;
    // [4,3]
    // graph[4][3] = 1;

    // 그래프에 이긴사람 표시
    for (int i = 0;i < results.size();i++) {
        graph[results[i][0]][results[i][1]] = 1;
    }

    // 플로이드
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            for (int k = 1;k <= n;k++) {
                if (graph[j][i] == 1 && graph[i][k] == 1) graph[j][k] = 1;

                for (int i = 1;i <= n;i++) {
                    int cnt = 0;
                    for (int j = 1;j <= n;j++) if (graph[i][j] == 1 || graph[j][i] == 1) cnt++;
                    if (cnt == n - 1) answer++;
                }

                return answer;
            }