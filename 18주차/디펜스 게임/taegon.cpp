#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int total = 0;
    //우선순위 queue를 사용한다
    priority_queue<int, vector<int>, greater<int>> big;
    //무적권이 enemy보다 많은경우 
    if (k >= enemy.size()) {
        return enemy.size();
    }
    //무적권 수만큼 big에 저장
    for (int i = 0; i < k; i++)
        big.push(enemy[i]);
    answer = k;


    for (int i = k; i < enemy.size(); i++) {
        //queue에 저장된 최소값이 enemy보다 작은 경우
        if (big.top() < enemy[i]) {
            //queue에서 최소값 빼고 enemy 저장
            total += big.top();
            big.pop();
            big.push(enemy[i]);
        }
        else {
            total += enemy[i];
        }
        answer++;
        //total이 더 커지면 마지막 더한 enemy 빼줘야 한다.
        if (total > n) {
            answer--;
            break;
        }

    }

    return answer;
}