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
