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

    // ���� ĥ���� ���̶�� ����
    for (int i = 1;i <= n;i++) sections[i] = true;

    // �Ϻ� ����Ʈ ������
    for (int i = 0;i < section.size();i++) sections[section[i]] = false;

    // ����Ʈ �������� ������ ĥ�ϱ�
    for (int i = 1;i <= n;i++)
        if (sections[i] == false) section_faint(i, m);

    return answer;
}