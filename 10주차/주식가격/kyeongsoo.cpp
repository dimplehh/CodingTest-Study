#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
int price_arr[10001] = {0}; 

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> stk;
    for(int idx = 0; idx < prices.size(); idx++){
        while(stk.size() > 0 && prices[stk.top()] > prices[idx]){
            int k = stk.top();
            stk.pop();
            answer[k] = idx - k;
        }
        stk.push(idx);
    }
    
    while(!stk.empty()){
        int k = stk.top();
        stk.pop();
        answer[k] = prices.size()-k-1;
    }
    return answer;
}
