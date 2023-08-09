#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 999999

using namespace std;

// dfs -> 시간초과

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[101][101];
int depth[101][101];

void bfs(vector<string> board, int x, int y) {
    queue<pair<int, int>> q;
    for (int i = 0;i < 100;i++) for (int j = 0;j < 100;j++) depth[i][j] = INF; // 이동깊이 초기화
    depth[y][x] = 0; // 이동 깊이
    visited[y][x] = true;
    q.push({ x, y });

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        //상하좌우 이동
        for (int i = 0;i < 4;i++) {

            int next_x = cur_x;
            int next_y = cur_y;

            // 장애물 만날때까지 이동 & 맵 끝까지 이동 
            while (true) {

                next_x += dx[i];
                next_y += dy[i];

                // 큐에 넣을 다음 위치가 맵 밖인 경우 이동 정지
                if (next_x < 0 || next_x >= board[0].size() || next_y < 0 || next_y >= board.size()) {
                    next_y -= dy[i];
                    next_x -= dx[i];
                    break;
                }
                // 큐에 넣을 다음 위치가 장애물인 경우 이동 정지
                if (board[next_y][next_x] == 'D') {
                    next_y -= dy[i];
                    next_x -= dx[i];
                    break;
                }

            }

            // 방문 안한 경우에만 큐에 넣고 다시 bfs 돌린다
            if (!visited[next_y][next_x]) {
                visited[next_y][next_x] = true;
                depth[next_y][next_x] = MIN(depth[next_y][next_x], depth[cur_y][cur_x] + 1);
                q.push({ next_x,next_y });
            }
        }
    }
}

int solution(vector<string> board) {
    int answer = INF;

    for (int y = 0;y < board.size();y++) {
        for (int x = 0;x < board[0].size();x++) {
            if (board[y][x] == 'R') { bfs(board, x, y); }
        }
    }
    for (int y = 0;y < board.size();y++) {
        for (int x = 0;x < board[0].size();x++) {
            if (board[y][x] == 'G') { if (depth[y][x] != INF) answer = depth[y][x]; }
        }
    }

    if (answer == INF) answer = -1;

    return answer;
}

int main() {
    solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
}