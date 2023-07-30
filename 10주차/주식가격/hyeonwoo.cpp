#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer;
    stack<int> s; // 상승세 담는 스택
    int temp;

    for (int i = 0;i < prices.size() - 1;i++) {
        for (int j = i;j < prices.size() - 1;j++) {
            // 상승세만 스택에 담기
            if (prices[j] >= prices[i]) s.push(prices[j]);
            else break;
        }
        // 스택에 담긴 숫자 수 체크해서 answer 에 담기
        // 만약 스택이 비어있으면 바로 다음에 가격 떨어지는 경우이므로 temp = 1
        if (s.empty()) temp = 1;
        temp = 0;

        // 상승세 비어있을때까지 스택에 있는 수 체크 후 answer 에 삽입
        while (!s.empty()) {
            s.pop();
            temp++;
        }
        answer.push_back(temp);
    }
    // 마지막은 무조건 0
    answer.push_back(0);

    return answer;

}