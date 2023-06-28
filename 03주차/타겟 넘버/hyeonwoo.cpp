#include <string>
#include <vector>

using namespace std;

int answerCnt = 0;

// 재귀함수(=DFS)
void DFS(vector<int> _numbers, int _target, int sum = 0, int idx = 0) {
    if (_numbers.size() == idx) { // 종료조건, numbers 최대값까지 가면 정산
        if (sum == _target) answerCnt++;
    }
    else { // numbers 최대값까지 sum 계산
        DFS(_numbers, _target, sum + _numbers[idx], idx + 1);
        DFS(_numbers, _target, sum - _numbers[idx], idx + 1);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target);
    return answerCnt;
}