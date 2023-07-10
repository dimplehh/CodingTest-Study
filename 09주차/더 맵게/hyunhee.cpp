#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scov; //heap을 의미, 자동 오름차순정렬되는 queue (그냥 <int>면 내림차순 정렬한다. 복잡하지만 외워야함.)
    sort(scoville.begin(), scoville.end());
    for(int i = 0; i < scoville.size(); i++)
        scov.push(scoville[i]);
    for(int i = 0; i < scoville.size(); i++)
    {
        if(scov.top() < K)
        {
            int temp = scov.top();
            scov.pop();
            scov.push(temp + scov.top() * 2);
            scov.pop();
            answer++;
        }
        else
            return answer;
    }
    return -1;
}
