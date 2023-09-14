#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stack;
    int cnt = 1;
    int orderCount = 0;

    while (orderCount < order.size()) {
        if (!stack.empty()) {
            if (stack.top() == order[orderCount]) {
                stack.pop();
                answer++;
                orderCount++;
            }
            else {
                stack.push(cnt);
                cnt++;
            }
        }
        else {
            stack.push(cnt);
            cnt++;
        }

        if (order.empty())
            break;
        if (!stack.empty()) {
            if (stack.top() > order[orderCount])
                break;
        }

    }

    return answer;
}