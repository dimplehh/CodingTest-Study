#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    bool visited[101] = { false, };
    int computers[101][101] = { 0 };
    int computerCnt, T, virused, a, b;
    int answer = 0;

    cin >> computerCnt; // 컴퓨터 수
    cin >> T; // 몇번 반복해서 입력받는지

    while (T--) {
        cin >> a >> b;
        computers[a][b] = computers[b][a] = 1;
    }

    q.push(1), visited[1] = true; // 1번 컴터 감염

    while (!q.empty()) {
        int virused = q.front();
        q.pop();

        // 연결된 컴퓨터 찾고 방문하지 않았다면 바이러스 감염
        for (int i = 1;i <= computerCnt;i++) {
            if (computers[virused][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                answer++;
            }
        }
    }

    cout << answer;
}