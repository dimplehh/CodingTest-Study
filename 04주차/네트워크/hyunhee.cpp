#include <string>
#include <vector>

using namespace std;
bool isVisited[200] = {false, };
void DFS(int cur, int n, vector<vector<int>> computers)
{
    isVisited[cur] = true;
    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i] && computers[cur][i] == 1)
            DFS(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(!isVisited[i]){
            DFS(i, n, computers);
            answer++;
        }
    }
    return answer;
}
