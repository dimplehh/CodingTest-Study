#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<int> temp;
    for(int i = 0; i < prices.size(); i++)
    {
        while(!temp.empty() && prices[temp.top()] > prices[i])
        {
            answer[temp.top()] = i - temp.top(); 
            temp.pop();
        }
        temp.push(i); //없으면 넣어라 (인덱스번호를 넣어야 수월한 참조가 가능..)
    }
    while(!temp.empty())
    {
        answer[temp.top()] = prices.size() - temp.top() - 1;
        temp.pop();
    }
    return answer;
}
