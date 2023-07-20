#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer;
    stack<int> s; // ��¼� ��� ����
    int temp;

    for (int i = 0;i < prices.size() - 1;i++) {
        for (int j = i;j < prices.size() - 1;j++) {
            // ��¼��� ���ÿ� ���
            if (prices[j] >= prices[i]) s.push(prices[j]);
            else break;
        }
        // ���ÿ� ��� ���� �� üũ�ؼ� answer �� ���
        // ���� ������ ��������� �ٷ� ������ ���� �������� ����̹Ƿ� temp = 1
        if (s.empty()) temp = 1;
        temp = 0;

        // ��¼� ������������� ���ÿ� �ִ� �� üũ �� answer �� ����
        while (!s.empty()) {
            s.pop();
            temp++;
        }
        answer.push_back(temp);
    }
    // �������� ������ 0
    answer.push_back(0);

    return answer;

}