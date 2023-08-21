#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m, k, x, y, answer = 0;

bool visited[60][60];
int map[60][60];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0)
                continue;

            if (!visited[nx][ny])
            {
                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }
}
int main()
{
    cin >> t;
    for (int ca = 0; ca < t; ca++)
    {
        cin >> n >> m >> k;
        answer = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            map[x][y] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1 && !visited[i][j])
                {
                    answer++;
                    bfs(i, j);
                }
            }
        }
        cout << answer << endl;
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
    }

}
