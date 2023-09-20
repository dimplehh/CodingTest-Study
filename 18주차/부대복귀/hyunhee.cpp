#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
//bfs
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> map[100001];
    vector<int> count(n + 1, -1);
    vector<int> answer;
    queue<pair<int,int>> q; //queue는 pair로 두 값을 갖도록 해야함(현재 위치, 현재 카운트)
    for(int i = 0; i <roads.size(); i++)
    {
        map[roads[i][0]].push_back(roads[i][1]);
        map[roads[i][1]].push_back(roads[i][0]);
    }//양방향 연결해주어야 하므로
    q.push({destination, 0});     //목적지 방향부터 시작
    count[destination] = 0;
    while(!q.empty())
    {
        int curPos = q.front().first; //queue가장 좌측의 첫 요소(position)
        int curCount = q.front().second; //queue가장 우측의 두번째 요소(count)
        q.pop();
        for(auto nextPos: map[curPos])//이런식으로 해줘야 map[curPos]에 쌓인 벡터요호들 하나씩 출력가능
        {
            if(count[nextPos] == -1 || count[nextPos] > curCount + 1) //방문한 적이 없거나 원래 카운트보다 작을 때
            {
                q.push({nextPos, curCount + 1});
                count[nextPos] = curCount + 1;   
            }
        }
    }
    for (auto src : sources) answer.push_back(count[src]);
    return answer;
}
