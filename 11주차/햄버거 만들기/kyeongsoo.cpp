#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> stk;
    stk.push(-1);
    for(int k : ingredient){
        if(stk.top() == 1 && k == 2) stk.top() = 12;
        else if(stk.top() == 12 && k == 3) stk.top() = 123;
        else if(stk.top() == 123 && k == 1) {stk.pop(); answer++;}
        else stk.push(k);
    }
    return answer;
}
