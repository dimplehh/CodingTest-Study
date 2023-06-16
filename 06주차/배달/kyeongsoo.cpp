#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAXValue 999999
using namespace std;



int solution(int N, vector<vector<int> > road, int K) {
    //한 노드에서 다른 노드까지의 최소 거리 = 다익스트라 알고리즘
    int answer = 0;
    int graph[51][51];
    fill(graph[0], graph[51], MAXValue);
    priority_queue<pair<int, int>> pq;
    pq.push(pair<int, int>(0, 1));

    for(vector<int> vec : road){
        graph[vec[0]][vec[1]] = min(vec[2], graph[vec[0]][vec[1]]);
        graph[vec[1]][vec[0]] = graph[vec[0]][vec[1]];
    }
    for(int i = 2; i <= N; i++){
        if(graph[1][i] < MAXValue)
            pq.push(pair<int, int>(graph[1][i], i));
    }
    graph[1][1] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        for(int i = 1; i <= N; i++){
            if(graph[cur][i] < MAXValue){
                if(graph[cur][i] + graph[1][cur] < graph[1][i]){
                    graph[1][i] = graph[cur][i] + graph[1][cur];
                    pq.push(pair<int, int>(graph[1][i], i));
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        if(graph[1][i] <= K) answer++;
    }

    return answer;
}
