#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> belt;//컨베이어벨트는 queue형태
    stack<int> temp;//보조는 stack형태임
    for (int i = 1; i <= order.size(); i++)//기본 컨베이어에는 무조건 순서대로 들어가야함
        belt.push(i);
    for(int i = 0; i < order.size(); i++)//order가 끝날 때까지
    {
        if(!belt.empty() && order[i] == belt.front())//컨베이어벨트 맨 우측이 order[i]이면
        {
            belt.pop();
            answer++;
        }
        else if(!temp.empty() && temp.top() == order[i])//보조 맨 좌측이 order[i]면
        {
            temp.pop();
            answer++;
        }
        else
        {
            if(order[i] > belt.front()) //꺼내야하는 order[i]가 belt.front()보다 크면(컨: 10 9 8 7...)
            {
                while(order[i] != belt.front())//그만큼을 꺼내서 보조 컨테이너에 넣을 수 있음
                {
                    int box = belt.front();
                    belt.pop();
                    temp.push(box);
                }
                if(!belt.empty() && order[i] == belt.front())//컨베이어 우측이 order[i]이므로 answer++
                {
                    belt.pop();
                    answer++;
                }   
            }
            else break;//꺼내야하는 order[i]가 belt.front()보다 좌측이면 컨베이어벨트에서 더이상 꺼낼 수 있는 것이 없음
        }   
    }
    return answer;
}
