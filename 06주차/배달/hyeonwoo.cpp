//#include <iostream>
//#include <vector>
//using namespace std;
//
//int graph[51][51] = { 0, };
//bool visited[51] = { 0 };
//
//void DFS_findGraph(int startNode, int destNode, int time, int N, int K) {
//
//    if (graph[startNode][destNode] == 0) return;     // 경로 존재하지 않으면 실행X
//    if (time > K) return; // 배달시간 초과시 실행X
//    visited[destNode] = true;
//    for (int i = 1;i <= N;i++) {
//        DFS_findGraph(destNode, i, graph[destNode][i] + time, N, K);
//    }
//}
//
//int solution(int N, vector<vector<int> > road, int K) {
//
//    int answer=0;
//    for (int i = 0;i < road.size();i++) {
//        //만약 경로 이미 존재하고, 그 값이 큰 가중치를 가지면 짧은 가중치로 변경
//        if (graph[road[i][1]][road[i][0]] > road[i][2])graph[road[i][1]][road[i][0]] = road[i][2];
//        if (graph[road[i][0]][road[i][1]] > road[i][2])graph[road[i][0]][road[i][1]] = road[i][2];
//        graph[road[i][1]][road[i][0]] = road[i][2];
//        graph[road[i][0]][road[i][1]] = road[i][2];
//    }
//    for (int i = 1;i <= N;i++) {
//        DFS_findGraph(1, i, graph[1][i], N, K);
//    }
//
//    visited[1] = true;
//    for (int i = 1;i < 51;i++) {
//        if (visited[i]) answer++;
//    }
//    return answer;
//}

#include <iostream>
#include <vector>
#define INF 9999999
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;

int dist[51] = { 0, };
int map[51][51] = { 0, };
int visited[51] = { 0, };

// 아직 방문하지 않은 노드 중 가장 가중치 작은 노드 인덱스 반환
int FindSmallNode(int N) {
    int min_dist = INF;
    int min_idx = -1;
    for (int i = 1;i <= N;i++) {
        if (!visited[i]) {
            if (dist[i] < min_dist) {
                min_dist = dist[i];
                min_idx = i;
            }
        }
    }
    return min_idx;
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int startNode = 1;

    // map 초기화
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            map[i][j] = INF;
    for (int i = 0;i < road.size();i++) { // 무방향 그래프
        map[road[i][0]][road[i][1]] = MIN(map[road[i][0]][road[i][1]], road[i][2]);
        map[road[i][1]][road[i][0]] = MIN(map[road[i][1]][road[i][0]], road[i][2]);
    }

    // 시작 노드에서 방문할 수 있는 노드들의 가중치 배열에 담기
    for (int i = 1;i <= N;i++) {
        dist[i] = map[startNode][i];
    }
    dist[startNode] = 0;
    visited[startNode] = true;

    // 다익스트라
    for (int i = 1;i <= N;i++) {
        int newNode = FindSmallNode(N);
        visited[newNode] = true;

        for (int j = 1;j <= N;j++) {
            if (!visited[j]) {
                dist[j] = MIN(dist[j], dist[newNode] + map[newNode][j]);
            }
        }
    }

    // dist에 담긴 배달시간 비교해서 정답 수 카운트
    for (int i = 1;i <= N;i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;

}