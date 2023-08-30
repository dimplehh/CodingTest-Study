#include <string>
#include <vector>
#include <iostream>
#define INF 999
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;

int alphaMoves[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
int moveCounts[21];
string initalName[21];

int solution(string name) {
    int answer = 0;             // ���Ʒ��� �����̴� Ƚ��
    int minMoves = name.size() - 1;   // �¿�� �����̴� Ƚ��

    // ���� ó��(����) ��ġ���� ���������� �̵� ( name[0] -> name[1] )
    for (int i = 0;i < name.size();i++) {
        answer += alphaMoves[name[i] - 'A'];

        // ���� ��ġ�� 'A'�� ���, ������/������ ��
        // J J A A A A Z Z
        // 2��° J���� 1��° Z�� �̵��Ҷ� �̵�Ƚ��
        //      - ������� �״�� �̵��� : temp - i
        //      - ������ �̵��� : i + name.size() - next
        int next = i + 1;
        while (name[next] == 'A' && next < name.size()) next++;

        // �̵��ϴ� ���� ���� ������ �̵�Ƚ���� ����
        int left = i;
        int right = name.size() - next;
        minMoves = MIN(minMoves, left + right + MIN(left, right));
    }

    cout << answer + minMoves;

    return answer + minMoves;
}

int main() {
    solution("JEROEN");
}