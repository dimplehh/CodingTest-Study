#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    const int INF = 987654321;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        graph[i][i] = 0;
    }

    for (vector<int> result : results) {
        int winner = result[0];
        int loser = result[1];
        graph[winner][loser] = 1;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        bool canDetermine = true;
        for (int j = 1; j <= n; ++j) {
            if (i != j && (graph[i][j] == INF && graph[j][i] == INF)) {
                canDetermine = false;
                break;
            }
        }
        if (canDetermine) {
            answer++;
        }
    }

    return answer;
}
