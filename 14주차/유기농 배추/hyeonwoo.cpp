#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <cstring>

#define MAX_SIZE 100
#define INF 0x7fffffff

using namespace std;
int n, k, d;

// �� �� �� �� 
int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

// ���߸� ���� ����
bool board[51][51] = { 0, };

// �迭 �湮 ���� üũ 
bool visited[51][51] = { 0, };

void dfs(int x, int y) {

    // x,y ��ǥ �湮 ǥ�� 
    visited[x][y] = true;

    // �� �� �� ��� �̵� �ϸ� Ž�� 
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        // �迭�� �ε����� ���� �ʵ��� 
        if (ax < 0 || ay < 0 || ax >= n || ay >= k)
            continue;

        // ���߰� ������ Ż�� / �湮�ߴٸ� Ż�� 
        if (!board[ax][ay] || visited[ax][ay])
            continue;

        dfs(ax, ay);
    }
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    // �׽�Ʈ ���̽� ��
    while (t--) {
        cin >> n >> k >> d;

        // ���� ���� �� üũ
        for (int i = 0; i < d; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = true;
        }

        // ���� ���� �� ã�Ƽ� dfs ������ ī��Ʈ
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (board[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        }

        cout << count << "\n";
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}