#include <string>
#include <vector>
#include <queue>
#define max(a,b)(((a)>(b))?(a):(b))

using namespace std;

int answer = 0;



// // ����Ž�� - �ð��ʰ�
// 
//vector<int> enemies;
//void DFS(int n, int k, int round=0) {
//    if (n <= 0) {
//        answer = max(round-1, answer);
//        return;
//    }
//    if (round == enemies.size()) {
//        answer = enemies.size();
//        return;
//    }
//    if (k != 0) DFS(n, k - 1, round + 1);
//    DFS(n - enemies[round], k, round + 1);
//}


int solution(int n, int k, vector<int> enemy) {

    // // ����Ž�� - �ð��ʰ�
    //enemies = enemy;
    //DFS(n, k);

    priority_queue<int> pq;
    int nextLife = n;
    int invinsible = k;

    answer = enemy.size();

    for (int i = 0;i < enemy.size();i++) {

        nextLife -= enemy[i];
        pq.push(enemy[i]);

        // ���� ���� ����� 0���� ������ ������ ���
        if (nextLife < 0) {
            // ������ ���
            if (invinsible > 0 && !pq.empty()) {
                nextLife += pq.top();
                pq.pop();
                invinsible--;
            }
            // ������ ���� ��� answer ���� �� break
            else {
                answer = i;
                break;
            }
        }
    }


    return answer;
}