#include <string>
#include <vector>

using namespace std;

int answerCnt = 0;

// ����Լ�(=DFS)
void DFS(vector<int> _numbers, int _target, int sum = 0, int idx = 0) {
    if (_numbers.size() == idx) { // ��������, numbers �ִ밪���� ���� ����
        if (sum == _target) answerCnt++;
    }
    else { // numbers �ִ밪���� sum ���
        DFS(_numbers, _target, sum + _numbers[idx], idx + 1);
        DFS(_numbers, _target, sum - _numbers[idx], idx + 1);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target);
    return answerCnt;
}