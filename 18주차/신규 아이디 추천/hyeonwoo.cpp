#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계 - 대문자를 소문자로
    for (int i = 0;i < new_id.size();i++) if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] += ('a' - 'A');

    // 2단계 - 특수문자제거
    for (int i = 0;i < new_id.size();i++) {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        else if (new_id[i] >= 'a' && new_id[i] <= 'z') continue;
        else if (new_id[i] >= '0' && new_id[i] <= '9') continue;
        new_id.erase(i, 1);
        i--;
    }

    // 3단계 - "..." -> "."
    for (int i = 0;i < new_id.size() - 1;i++) {
        if (new_id[i] == '.') {
            int cnt = 0;
            while (new_id[i + cnt + 1] == '.') cnt++;
            new_id.erase(i, cnt);
        }
    }

    // 4단계 - 처음/끝 마침표제거
    if (new_id[0] == '.') new_id.erase(0, 1);
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

    // 5단계 - 빈문자열이면 a 대입
    if (new_id == "") new_id = "a";

    // 6단계 - 16자 이상이면 15개 문자 제외 모두 제거
    if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);// 마침표 끝에 있으면 제거

    // 7단계 - 2자 이하면 마지막 문자를 new_id길이가 3될때까지 반복
    if (new_id.size() <= 2) {
        char iterChar = new_id[new_id.size() - 1];
        while (new_id.size() <= 2) new_id += iterChar;
    }

    return new_id;
}