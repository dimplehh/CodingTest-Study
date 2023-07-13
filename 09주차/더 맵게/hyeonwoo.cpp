#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {

    int answer = 0;
    int temp;
    // 우선순위 큐 기본값은 내림차순 (less<int>), 오름차순으로 맞춰준다 -> [12,10,9,3,2,1]
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());

    // 스코빌지수 낮으면 섞는다  (스코빌지수 K이상이 될 때까지 + 큐에 남은 값이 없을때까지)
    while (pq.top() < K && pq.size() > 1) {
        answer++;
        temp = pq.top(); // 첫번째값
        pq.pop();
        temp += pq.top() * 2; // 두번째값
        pq.pop();
        pq.push(temp);
    }

    // 스코빌지수 다 섞었는디 K보다 다 작으면 -1 리턴
    if (pq.top() < K) return -1;
    else return answer;
}