//첫 시도 DFS : 테케는 성공하지만 효율성 테스트 실패
#include<vector>
#include<iostream>
using namespace std;
bool visited[101][101];
int answer = 10001;
void DFS(int x, int y, vector<vector<int>> maps, int count)
{
    if(x < 0 || y < 0 || x >= maps.size() || y >= maps[0].size()) //maps주의 maps[1]아니라 maps라고 해야 길이임.
        return;
    else if(maps[x][y] == 0 || visited[x][y])
        return;
    else if(x == maps.size() - 1 && y == maps[0].size() - 1)
    {
        if (answer > count)
            answer = count;
        return ;
    }
    visited[x][y] = true;
    DFS(x + 1, y, maps, count + 1);
    DFS(x - 1, y, maps, count + 1);
    DFS(x, y + 1, maps, count + 1);
    DFS(x, y - 1, maps, count + 1);
    visited[x][y] = false;
}
    
int solution(vector<vector<int> > maps)
{
    int count = 1;
    DFS(0, 0, maps, count);
    if (answer == 10001)
        answer = -1;
    return answer;
}

//두번째 시도 : BFS -> 통과
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
bool visited[101][101];
int answer = 10001;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int solution(vector<vector<int> > maps)
{
    queue <pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    visited[0][0] = true;
    while(!q.empty())
    {
        int count = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == maps.size() - 1 && y == maps[0].size() - 1)
        {
            cout << count << endl;
            answer = count;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size())
                continue;
            else if(visited[nx][ny] || maps[nx][ny] == 0)
                continue;
            visited[nx][ny] = 1;
            q.push({count + 1, {nx, ny}});
        }
    }
    if(answer == 10001)
        answer = -1;
    return answer;
}
