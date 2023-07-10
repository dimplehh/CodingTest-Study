#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

const int MAX = 50001;
using namespace std;
bool isGate[MAX];
bool isSummit[MAX];
int dist[MAX];

//다익스트라 알고리즘
vector<int> Dijkstra(vector<pair<int, int>> graph[MAX], int n, vector<int> &gates) {
    vector<vector<int>> result;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    fill_n(dist, MAX, -1);
    //게이트 간 이동 제거
    for (int gate : gates) {
        isGate[gate] = true;
        pq.push({ 0, gate });
    }

    int w, k;
    while (!pq.empty()) {
        w = pq.top()[0];
        k = pq.top()[1];
        pq.pop();

        if (isSummit[k]) {
            result.push_back({ w, k });
            continue;
        }

        for (pair<int, int> node : graph[k]) {
            if (isGate[node.first])
                continue;
            int wt = max(w, node.second);
            if (dist[node.first] == -1 || wt < dist[node.first]) {
                dist[node.first] = wt;
                pq.push({ wt, node.first });
            }
        }
    }

    sort(result.begin(), result.end());
    reverse(result[0].begin(), result[0].end());
    return result[0];
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = { n, 987654321 };
    vector<pair<int, int>> graph[MAX];
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int x, y, w;
    for (vector<int> path : paths) {
        x = path[0], y = path[1], w = path[2];
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }


    for (int summit : summits) {
        isSummit[summit] = true;
    }

    answer = Dijkstra(graph, n, gates);


    return answer;
}
