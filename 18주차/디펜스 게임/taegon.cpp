#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int total = 0;
    //�켱���� queue�� ����Ѵ�
    priority_queue<int, vector<int>, greater<int>> big;
    //�������� enemy���� ������� 
    if (k >= enemy.size()) {
        return enemy.size();
    }
    //������ ����ŭ big�� ����
    for (int i = 0; i < k; i++)
        big.push(enemy[i]);
    answer = k;


    for (int i = k; i < enemy.size(); i++) {
        //queue�� ����� �ּҰ��� enemy���� ���� ���
        if (big.top() < enemy[i]) {
            //queue���� �ּҰ� ���� enemy ����
            total += big.top();
            big.pop();
            big.push(enemy[i]);
        }
        else {
            total += enemy[i];
        }
        answer++;
        //total�� �� Ŀ���� ������ ���� enemy ����� �Ѵ�.
        if (total > n) {
            answer--;
            break;
        }

    }

    return answer;
}