#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);
        if(i >= k)
        {
            int temp = pq.top();
            pq.pop();
            n -= temp;
            if(n < 0)
                break;
        }
        answer++;
    }
    return answer;
}
