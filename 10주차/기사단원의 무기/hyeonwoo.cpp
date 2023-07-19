#include <string>
#include <vector>

using namespace std;

int arr[100000];

int solution(int number, int limit, int power) {

    int answer = 0;

    // ����� �� ���� �迭 number ũ�⸸ŭ �ʱ�ȭ
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3;i <= number;i++) {
        arr[i] = 2;
        for (int j = 2;j <= i / 2;j++) {
            if (i % j == 0) arr[i]++;
        }
    }

    // ����� �� ���� �迭���� limit���� ū �� �˻�
    for (int i = 1;i <= number;i++) {
        if (arr[i] > limit) answer += power; // ���� limit���� ũ�� answer�� power �� ����
        else answer += arr[i]; // �׿��� ���(limit ���� �۰ų� ������) �׳� ����� ���� ����
    }

    return answer;
}