#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> v[51];
vector<int> dist;
//다익스트라
void dijkstra()
{
    int pos;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;//우선순위큐에만 top()존재함.
    q.push({1, 0});
    while(!q.empty()){
        pos = q.top().first;
        q.pop();
        for(int i = 0; i<v[pos].size(); i++){
            if(dist[v[pos][i].first] > dist[pos] + v[pos][i].second){ //dist에 저장된 최소거리보다 새로 계산한 값이 더 최솟값이므로 이때만 새로운 연산 필요
                dist[v[pos][i].first] = dist[pos] + v[pos][i].second;
                q.push({v[pos][i].first, v[pos][i].second});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i = 0; i < road.size(); i++)
    {
        int a = road[i][0], b = road[i][1], c = road[i][2];
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }//초기화
    
    dist.resize(N + 1, 1e9); //resize : 배열 크기 재할당 함수
    dist[1] = 0; //1에서 i까지의 최소거리
    dijkstra();
    
    for(int i = 1; i < dist.size(); i++) if(dist[i] <= K) answer++;
    return answer;
}
