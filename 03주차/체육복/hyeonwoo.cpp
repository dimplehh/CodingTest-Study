#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int students[31] = { 0, };
    int answer = n;

    // ü���� ��� �ִٰ� ����, ��� �л�=1
    for (int i = 1; i <= n; i++) {
        students[i] = 1;
    }
    // ü���� �������ؼ� ���� �л� -1
    for (int i = 0; i < lost.size(); i++) {
        students[lost[i]]--;
    }
    // ü���� ���� �ִ� �л� +1
    for (int i = 0; i < reserve.size(); i++) {
        students[reserve[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) { // ü���� ���� �л��� ��� �� �л��� ���� �ִٸ� �����´�
            if (students[i - 1] == 2) {
                students[i - 1]--;
                students[i]++;
                continue;
            }
            if (students[i + 1] == 2) {
                students[i + 1]--;
                students[i]++;
                continue;
            }
        }
    }

    // ü���� ���� �л�����ŭ ��ü ������ ���ֱ�
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) answer--;
    }
    return answer;
}