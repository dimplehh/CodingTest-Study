#include <string>
#include <vector>
#include <stack>

using namespace std;

// 1 2 3 4 5
// 4 3 1 2 5

int solution(vector<int> order) {
    int answer = 0;
    int idx = 0; // �ù�������� �θ� ��ȣ

    stack<int> subContainer; // ���� �����̳�

    // �̶� i�� �ڽ� ��ȣ
    for (int i = 1;i <= order.size();i++) {
        // step1. �ù��簡 �˷��� ������ �ڽ� ��ȣ�� ��ġ�ϸ�, Ʈ���� �ڽ� �ƴ´�. ��ġ���� �ʴ� ��� ���������̳� ��Ʈ�� ��´�
        if (order[idx] == i) { idx++; answer++; }
        else subContainer.push(i);

        // step2. ���������̳ʺ�Ʈ �˻�
        while (!subContainer.empty()) {
            if (subContainer.top() == order[idx]) { answer++; idx++; subContainer.pop(); }
            else break;
        }
    }

    return answer;
}