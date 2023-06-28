#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool visited[8] = {false,};
int answer = 0;
void DFS(int k, vector<vector<int>> dungeons, int cnt)
{
    answer = max(answer, cnt);
    for (int i=0; i<dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            DFS(k - dungeons[i][1], dungeons, cnt + 1);
            visited[i] = false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    DFS(k, dungeons, 0);
    return answer;
}
