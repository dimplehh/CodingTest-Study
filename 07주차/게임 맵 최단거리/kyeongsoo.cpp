#include<vector>
#include <iostream>
#include <queue>
#include <iostream>
using namespace std;

int bfs(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;
    vector<vector<int>> dir = { {-1,0},{1,0}, {0,1}, {0,-1} };

    queue<vector<int>> q;
    vector<int> arr;
    int hx, hy;
    q.push({ 1, 0, 0 });
    while (!q.empty()) {
        arr = q.front();
        if(arr[1] == n-1 && arr[2] == m-1)
            return arr[0];
        q.pop();
        for (int i = 0; i < dir.size(); i++) {
            int hx = arr[1] + dir[i][0], hy = arr[2] + dir[i][1];
            if (hx < 0 || hy < 0 || hx >= n || hy >= m)
                continue;
            else if (maps[hx][hy] == 0 || visited[hx][hy])
                continue;
            visited[hx][hy] = true;
            q.push({ arr[0] + 1, hx, hy });
        }
    }
    return -1;
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    answer = bfs(maps);
    return answer;
}
