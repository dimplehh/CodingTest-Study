#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

// �޸� 
// 
// map Ž�� �ӵ�            :   O(logN)
// unordered_map Ž�� �ӵ�  :   O(1)
//
// map �� �ڵ� �������� ����, unordered_map�� ����X
// �� �� �ߺ� �����

// ó������ typedef struct �Ἥ ����ü�� ��װ�, map���� �㰬�ٰ� �ð����⵵���� ������..! ��


// ������ ��� �ؽø�
unordered_map<string, vector<int>> applicant_info;


// ������ ���� �����ϴ� �Լ�
void Save_applicant_info(string str) {
    string item[4];
    int score, idx = 0;
    item[0] = item[1] = item[2] = item[3] = "";

    // info �Ľ�, "a b c d 100" -> "abcd", 100
    for (int i = 0;i < str.length();i++) {
        if (str[i] != ' ') item[idx] += str[i];
        else {
            idx++;
            if (idx == 4) score = stoi(str.erase(0, i));
        }
    }

    // �ؽøʿ� ����, "a b c d 100" -> ["abcd",100],["-bcd",100],["a-cd",100],["ab-d",100], ... ["----",100]
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

    // ������ ����ŭ �ݺ� , ������ ���� ����
    for (int i = 0;i < info.size();i++) {
        Save_applicant_info(info[i]);
    }

    // ���� Ž��
    for (int i = 0;i < query.size();i++) {
        string item[100];
        int idx = 0; // ���� �Ľ� �ε���
        int res = 0; // ���ǿ� �´� ���� �����

        // ���� �Ľ�
        for (int j = 0;j < query[i].size();j++) {
            if (query[i][j] != ' ') {
                item[idx] += query[i][j];
            }
            else idx++;
        }
        string q = item[0] + item[2] + item[4] + item[6]; // ���ڿ� "and" �� ������ ���� ���ڿ�
        int score = stoi(item[7]); // ����

        // ������ ������ ���� ã�Ƽ� scores �迭�� ����
        vector<int> scores = applicant_info[q];

        // ����� ī��Ʈ
        int cnt = 0;
        for (int j = 0;j < scores.size();j++) {
            if (scores[j] >= score) cnt++;
        }

        // ����� ����
        answer.push_back(cnt);
    }

    return answer;
}