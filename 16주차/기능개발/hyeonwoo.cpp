#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // 남은 날짜 큐
    queue<int> leftDays;
    for (int i = 0;i < progresses.size();i++) {
        if ((100 - progresses[i]) % speeds[i] != 0) leftDays.push((100 - progresses[i]) / speeds[i] + 1);
        else leftDays.push((100 - progresses[i]) / speeds[i]);
    }

    // 큐에서 하나 꺼내고 시작
    int day = leftDays.front();
    int count = 1;
    leftDays.pop();

    // 남은 일수 큐 empty 될 때까지 검사
    while (!leftDays.empty()) {
        int current = leftDays.front();
        leftDays.pop();

        if (day >= current) count++;
        else { // 작업 일수가 크면 카운트 초기화
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