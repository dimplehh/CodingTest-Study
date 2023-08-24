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

    cin >> computerCnt; // ��ǻ�� ��
    cin >> T; // ��� �ݺ��ؼ� �Է¹޴���

    while (T--) {
        cin >> a >> b;
        computers[a][b] = computers[b][a] = 1;
    }

    q.push(1), visited[1] = true; // 1�� ���� ����

    while (!q.empty()) {
        int virused = q.front();
        q.pop();

        // ����� ��ǻ�� ã�� �湮���� �ʾҴٸ� ���̷��� ����
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