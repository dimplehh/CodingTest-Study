#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int students[31] = { 0, };
    int answer = n;

    // 체육복 모두 있다고 가정, 모든 학생=1
    for (int i = 1; i <= n; i++) {
        students[i] = 1;
    }
    // 체육복 도난당해서 없는 학생 -1
    for (int i = 0; i < lost.size(); i++) {
        students[lost[i]]--;
    }
    // 체육복 여분 있는 학생 +1
    for (int i = 0; i < reserve.size(); i++) {
        students[reserve[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) { // 체육복 없는 학생의 경우 옆 학생이 여분 있다면 빌려온다
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

    // 체육복 없는 학생수만큼 전체 수에서 빼주기
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) answer--;
    }
    return answer;
}