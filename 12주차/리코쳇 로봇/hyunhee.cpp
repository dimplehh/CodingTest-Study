#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 10000

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[101][101];
int depth[101][101] = {0,};
void BFS(vector<string> &board, int rowCnt, int colCnt, int rRow, int rCol)
{
    queue<pair<int,int>> q;
    fill(depth[0], depth[101], INF);//시작요소,끝요소,채워넣을 값
    q.push({rRow, rCol});
    visited[rRow][rCol] = 1;
    depth[rRow][rCol] = 0;
    
    while(!q.empty())
    {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ny = curRow;
            int nx = curCol;
            while(1)
            {
                ny += dy[i];
                nx += dx[i];
                if(ny<0 || ny>=rowCnt || nx<0 || nx>=colCnt ||
                  board[ny][nx] == 'D')
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            depth[ny][nx] = depth[curRow][curCol] + 1;
            q.push({ny, nx});
        }
    }
}

int solution(vector<string> board) {
    int y; int x; int gy; int gx; 
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[i].size();j++)
            if(board[i][j]=='R')
            {
              y = i; x = j;   
            }
            else if(board[i][j]=='G')
            {
              gy = i; gx = j;   
            }
    BFS(board, board.size(), board[y].size(), y, x);
    if(depth[gy][gx]==INF) return -1;
        return depth[gy][gx];
}
