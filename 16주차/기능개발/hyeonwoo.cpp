#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // ���� ��¥ ť
    queue<int> leftDays;
    for (int i = 0;i < progresses.size();i++) {
        if ((100 - progresses[i]) % speeds[i] != 0) leftDays.push((100 - progresses[i]) / speeds[i] + 1);
        else leftDays.push((100 - progresses[i]) / speeds[i]);
    }

    // ť���� �ϳ� ������ ����
    int day = leftDays.front();
    int count = 1;
    leftDays.pop();

    // ���� �ϼ� ť empty �� ������ �˻�
    while (!leftDays.empty()) {
        int current = leftDays.front();
        leftDays.pop();

        if (day >= current) count++;
        else { // �۾� �ϼ��� ũ�� ī��Ʈ �ʱ�ȭ
            answer.push_back(count);
            day = current;
            count = 1;
        }
    }

    answer.push_back(count);

    return answer;
}

int main() {
    solution({ 93,30,55 }, { 1,30,5 });
}