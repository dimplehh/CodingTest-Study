#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int w = maps.size();
    int h = maps[0].size();
    bool visited[110][110];
    bool flag = false;
    memset(visited, false, sizeof(visited));
    
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = true;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(x == (w - 1) && y == (h - 1))
        {
            answer = cnt;
            break;
        }
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= w || ny >= h || !maps[nx][ny])
                continue;
            
            if(!visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), cnt + 1));
            }
        }
    }
    if(answer != 0)
        return answer;
    else
        return -1;
}
