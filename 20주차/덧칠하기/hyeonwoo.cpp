#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool sections[100000] = { 0, };
int answer = 0;

void section_faint(int idx, int m) {
    for (int i = idx;i < idx + m;i++) {
        sections[i] = true;
    }
    //cout << idx;
    answer++;
}

int solution(int n, int m, vector<int> section) {

    // 전부 칠해진 것이라고 가정
    for (int i = 1;i <= n;i++) sections[i] = true;

    // 일부 페인트 벗겨짐
    for (int i = 0;i < section.size();i++) sections[section[i]] = false;

    // 페인트 벗겨진곳 있으면 칠하기
    for (int i = 1;i <= n;i++)
        if (sections[i] == false) section_faint(i, m);

    return answer;
}