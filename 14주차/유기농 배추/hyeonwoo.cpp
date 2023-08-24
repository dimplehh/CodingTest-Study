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

// 상 하 좌 우 
int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

// 배추를 심은 보드
bool board[51][51] = { 0, };

// 배열 방문 여부 체크 
bool visited[51][51] = { 0, };

void dfs(int x, int y) {

    // x,y 좌표 방문 표시 
    visited[x][y] = true;

    // 상 하 좌 우로 이동 하며 탐색 
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        // 배열의 인덱스를 넘지 않도록 
        if (ax < 0 || ay < 0 || ax >= n || ay >= k)
            continue;

        // 배추가 없으면 탈출 / 방문했다면 탈출 
        if (!board[ax][ay] || visited[ax][ay])
            continue;

        dfs(ax, ay);
    }
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    // 테스트 케이스 수
    while (t--) {
        cin >> n >> k >> d;

        // 배추 심은 밭 체크
        for (int i = 0; i < d; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = true;
        }

        // 배추 심은 밭 찾아서 dfs 돌려서 카운트
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