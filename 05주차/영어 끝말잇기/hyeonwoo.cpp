#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;


    int turn = 0;
    char lastChar = NULL;
    char firstChar;

    // �ؽÿ� ���� ���� - <���� ���ڿ� , n��° ���>
    unordered_map<string, int> h;

    for (int i = 0; i < words.size(); i++) {

        turn = 1 + i / n;
        firstChar = words[i][0];

        if (lastChar != NULL && lastChar != firstChar) { // ������ �ܾ�� ��ġ���� �ʴ� ��� ��
            answer.push_back((i % n) + 1);
            answer.push_back(turn);
            return answer;
        }
        if (h.find(words[i]) != h.end()) { // �ߺ��� �ܾ� ���ϸ� ��
            answer.push_back((i % n) + 1);
            answer.push_back(turn);
            return answer;
        }
        else { // �ؽøʿ� ���
            h.insert(make_pair(words[i], i));
            lastChar = words[i][words[i].size() - 1]; // �������� �θ� �ܾ� ����
        }
    }

    // ���������� �����ձ� �������
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}