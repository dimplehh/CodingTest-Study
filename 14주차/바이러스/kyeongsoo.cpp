#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

bool visited[101];

int BFS(vector<vector<int>>& graph, int n, int a) {
    int count = 0;
    
    visited[a] = true;
    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next_node : graph[node]) {
            if (visited[next_node])
                continue;
            visited[next_node] = true;
            count += 1;
            q.push(next_node);
        }
    }
    return count;
}

int main() {
    int n;
    int m;
    vector<vector<int>> graph(101);
    cin >> n;
    cin >> m;

    while (m > 0) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        m--;
    }
    cout << BFS(graph, n, 1);
    return 0;
}
