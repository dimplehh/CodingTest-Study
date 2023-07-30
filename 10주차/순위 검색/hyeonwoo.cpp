#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

// 메모 
// 
// map 탐색 속도            :   O(logN)
// unordered_map 탐색 속도  :   O(1)
//
// map 은 자동 오름차순 정렬, unordered_map은 정렬X
// 둘 다 중복 비허용

// 처음에는 typedef struct 써서 구조체로 담그고, map으로 담갔다가 시간복잡도에서 터졌다..! ㅠ


// 지원자 담는 해시맵
unordered_map<string, vector<int>> applicant_info;


// 지원자 정보 저장하는 함수
void Save_applicant_info(string str) {
    string item[4];
    int score, idx = 0;
    item[0] = item[1] = item[2] = item[3] = "";

    // info 파싱, "a b c d 100" -> "abcd", 100
    for (int i = 0;i < str.length();i++) {
        if (str[i] != ' ') item[idx] += str[i];
        else {
            idx++;
            if (idx == 4) score = stoi(str.erase(0, i));
        }
    }

    // 해시맵에 저장, "a b c d 100" -> ["abcd",100],["-bcd",100],["a-cd",100],["ab-d",100], ... ["----",100]
    applicant_info[item[0] + item[1] + item[2] + item[3]].push_back(score);
    applicant_info["-" + item[1] + item[2] + item[3]].push_back(score);
    applicant_info[item[0] + "-" + item[2] + item[3]].push_back(score);
    applicant_info[item[0] + item[1] + "-" + item[3]].push_back(score);
    applicant_info[item[0] + item[1] + item[2] + "-"].push_back(score);
    applicant_info["--" + item[2] + item[3]].push_back(score);
    applicant_info["-" + item[1] + "-" + item[3]].push_back(score);
    applicant_info["-" + item[1] + item[2] + "-"].push_back(score);
    applicant_info[item[0] + "--" + item[3]].push_back(score);
    applicant_info[item[0] + "-" + item[2] + "-"].push_back(score);
    applicant_info[item[0] + item[1] + "--"].push_back(score);
    applicant_info["---" + item[3]].push_back(score);
    applicant_info["--" + item[2] + "-"].push_back(score);
    applicant_info["-" + item[1] + "--"].push_back(score);
    applicant_info[item[0] + "---"].push_back(score);
    applicant_info["----"].push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    // 지원자 수만큼 반복 , 지원자 정보 저장
    for (int i = 0;i < info.size();i++) {
        Save_applicant_info(info[i]);
    }

    // 쿼리 탐색
    for (int i = 0;i < query.size();i++) {
        string item[100];
        int idx = 0; // 쿼리 파싱 인덱스
        int res = 0; // 조건에 맞는 쿼리 결과값

        // 쿼리 파싱
        for (int j = 0;j < query[i].size();j++) {
            if (query[i][j] != ' ') {
                item[idx] += query[i][j];
            }
            else idx++;
        }
        string q = item[0] + item[2] + item[4] + item[6]; // 문자열 "and" 를 제외한 쿼리 문자열
        int score = stoi(item[7]); // 점수

        // 쿼리로 지원자 정보 찾아서 scores 배열에 저장
        vector<int> scores = applicant_info[q];

        // 결과값 카운트
        int cnt = 0;
        for (int j = 0;j < scores.size();j++) {
            if (scores[j] >= score) cnt++;
        }

        // 결과값 저장
        answer.push_back(cnt);
    }

    return answer;
}