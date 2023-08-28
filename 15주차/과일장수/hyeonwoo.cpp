#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end());

    // 만들 수 있는 만큼 사과박스를 만든다
    int boxCnt = score.size() / m;
    for (int i = 1;i <= boxCnt;i++) {
        vector<int> box(score.end() - m * i, score.end() - m * (i - 1));
        answer += box.front() * m;
    }
    //cout << answer;
    return answer;
}