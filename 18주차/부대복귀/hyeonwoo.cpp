#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1000000000



// 메모 - 우선순위큐는 기본적으로 내림차순, pair 로 되어 있으면 첫번째꺼 내림차순 → 두번째꺼 내림차순


using namespace std;
vector<pair<int, int>> roadVector[100001]; // roadVector[i] = { 정점, 비용 } 
int dist[100001];


void dijkstra(int start) {
    priority_queue<pair<int, int>> pq; // pq[i] = { 정점, 비용 }
    dist[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        // 현재 정점 번호와 비용
        int cur = pq.top().first;
        int cur_cost = pq.top().second;
        pq.pop();

        // 최단거리 아니면 검사 X
        if (dist[cur] < cur_cost) continue;

        for (int i = 0;i < roadVector[cur].size();i++) {
            // 다음위치 정점 번호와 다음 비용
            int next = roadVector[cur][i].first;
            int next_cost = cur_cost + roadVector[cur][i].second;

            // 최소비용보다 더 저렴한 경우 교체
            if (next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({ next, next_cost });
            }
        }
    }
}


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    // 모든 거리 INF값으로
    for (int i = 0;i <= n;i++) dist[i] = INF;

    // 정점과 정점 사이 잇기 (비용=1)
    for (int i = 0;i < roads.size();i++) {
        roadVector[roads[i][0]].push_back({ roads[i][1],1 });
        roadVector[roads[i][1]].push_back({ roads[i][0],1 });
    }

    // 다익스트라
    dijkstra(destination);

    // 복귀 가능한지 여부 저장
    for (int i = 0;i < sources.size();i++) {
        if (dist[sources[i]] == INF) answer.push_back(-1);
        else answer.push_back(dist[sources[i]]);
    }

    return answer;
}
