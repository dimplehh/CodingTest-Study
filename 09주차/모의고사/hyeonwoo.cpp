#include <string>
#include <vector>
#include <list>
#include <algorithm>
#define MAX_PERSON 3

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // ������ 1,2,3
    vector<int> arr[MAX_PERSON];
    arr[0] = { 1,2,3,4,5 };
    arr[1] = { 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5 };
    arr[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int ptr[MAX_PERSON] = { 0 }; // ������
    int arrAnswerCnt[MAX_PERSON] = { 0 }; // ���� �� ���

    // answers�� ��� ���� ����ŭ ��
    for (int i = 0;i < answers.size();i++) {
        // ��� ����ŭ ��
        for (int j = 0;j < MAX_PERSON;j++) {
            // j�� ������ ��ȣ
            if (answers[i] == arr[j][(ptr[j]++) % arr[j].size()]) {
                arrAnswerCnt[j]++;
            }
        }
    }

    // ������� �߿� ���� ���� ���� ��� ���� ���� ����
    int maxAnswerCnt = 0;
    for (int i = 0;i < MAX_PERSON;i++) {
        if (arrAnswerCnt[i] > maxAnswerCnt) maxAnswerCnt = arrAnswerCnt[i];
    }

    // ���� ���� ���� ����� ���� ���� ��ġ�ϴ� ��� ���信 ���
    for (int i = 0;i < MAX_PERSON;i++) {
        if (arrAnswerCnt[i] == maxAnswerCnt) answer.push_back(i + 1);
    }

    // ����
    sort(answer.begin(), answer.end());

    return answer;
}