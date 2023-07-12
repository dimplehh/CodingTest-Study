#include <string>
#include <vector>
#include <list>
#include <algorithm>
#define MAX_PERSON 3

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // 수포자 1,2,3
    vector<int> arr[MAX_PERSON];
    arr[0] = { 1,2,3,4,5 };
    arr[1] = { 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5 };
    arr[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int ptr[MAX_PERSON] = { 0 }; // 포인터
    int arrAnswerCnt[MAX_PERSON] = { 0 }; // 정답 수 담기

    // answers에 담긴 정답 수만큼 비교
    for (int i = 0;i < answers.size();i++) {
        // 사람 수만큼 비교
        for (int j = 0;j < MAX_PERSON;j++) {
            // j는 수포자 번호
            if (answers[i] == arr[j][(ptr[j]++) % arr[j].size()]) {
                arrAnswerCnt[j]++;
            }
        }
    }

    // 찍은사람 중에 가장 많이 맞은 사람 정답 개수 저장
    int maxAnswerCnt = 0;
    for (int i = 0;i < MAX_PERSON;i++) {
        if (arrAnswerCnt[i] > maxAnswerCnt) maxAnswerCnt = arrAnswerCnt[i];
    }

    // 가장 많이 맞은 사람의 정답 수와 일치하는 사람 정답에 담기
    for (int i = 0;i < MAX_PERSON;i++) {
        if (arrAnswerCnt[i] == maxAnswerCnt) answer.push_back(i + 1);
    }

    // 정렬
    sort(answer.begin(), answer.end());

    return answer;
}