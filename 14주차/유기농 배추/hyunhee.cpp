#include <iostream>
#include <string.h>
using namespace std;

int M, N, K;
bool visited[50][50] = {false,};
int table[50][50] = {0,};
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >=M)
            continue;
        if(table[ny][nx] && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}


int main()
{
    int jirong,T;
    cin >> T;
    while(T--)
    {
        jirong = 0;
        memset(table, 0, sizeof(table));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;
        while(K--)
        {
            int x,y;
            cin >> x >> y;
            table[y][x] = 1;
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(table[i][j] && !visited[i][j]){
                    jirong++;
                    visited[i][j] = true;
                    dfs(i,j);
                }
            }
        }
        cout << jirong << endl;
    }
    return 0;
}
