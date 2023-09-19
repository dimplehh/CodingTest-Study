#include <string>
#include <vector>
#include <queue>
#define max(a,b)(((a)>(b))?(a):(b))

using namespace std;

int answer = 0;



// // 완전탐색 - 시간초과
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

    // // 완전탐색 - 시간초과
    //enemies = enemy;
    //DFS(n, k);

    priority_queue<int> pq;
    int nextLife = n;
    int invinsible = k;

    answer = enemy.size();

    for (int i = 0;i < enemy.size();i++) {

        nextLife -= enemy[i];
        pq.push(enemy[i]);

        // 만약 다음 목숨이 0보다 작으면 무적권 사용
        if (nextLife < 0) {
            // 무적권 사용
            if (invinsible > 0 && !pq.empty()) {
                nextLife += pq.top();
                pq.pop();
                invinsible--;
            }
            // 무적권 없는 경우 answer 갱신 후 break
            else {
                answer = i;
                break;
            }
        }
    }


    return answer;
}