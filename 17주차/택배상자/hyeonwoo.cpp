#include <string>
#include <vector>
#include <stack>

using namespace std;

// 1 2 3 4 5
// 4 3 1 2 5

int solution(vector<int> order) {
    int answer = 0;
    int idx = 0; // 택배아저씨가 부른 번호

    stack<int> subContainer; // 보조 컨테이너

    // 이때 i는 박스 번호
    for (int i = 1;i <= order.size();i++) {
        // step1. 택배기사가 알려준 순서와 박스 번호가 일치하면, 트럭에 박스 싣는다. 일치하지 않는 경우 보조컨테이너 벨트에 담는다
        if (order[idx] == i) { idx++; answer++; }
        else subContainer.push(i);

        // step2. 보조컨테이너벨트 검사
        while (!subContainer.empty()) {
            if (subContainer.top() == order[idx]) { answer++; idx++; subContainer.pop(); }
            else break;
        }
    }

    return answer;
}