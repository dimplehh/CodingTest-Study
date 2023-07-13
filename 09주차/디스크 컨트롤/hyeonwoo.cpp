#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct job {
    int request;
    int time;
};

struct cmp { // 시간 짧게 걸리는거 우선
    bool operator()(job a, job b) {
        return a.time > b.time;
    }
};

int solution(vector<vector<int>> jobs) {

    // 운영체제에서 SJF (Shortest Job First) 알고리즘과 같음
    // 가장 짧은 작업 우선
    int answer = 0;
    int timer = 0;
    int idx = 0;

    sort(jobs.begin(), jobs.end());
    // 실행시간 낮은게 우선순위 높음 
    // [[0, 3], [1, 9], [2, 6]]  →  [[1, 9], [2, 6], [0, 3]]
    priority_queue<job, vector<job>, cmp> pq;

    job j;
    while (idx < jobs.size() || !pq.empty()) {
        // 작업시간(timer) 내에 도착한 작업 요청(jobs[idx][0])이 있는 경우
        if (idx < jobs.size() && timer >= jobs[idx][0]) {
            j.request = jobs[idx][0];
            j.time = jobs[idx][1];
            idx++;
            pq.push(j);
            continue; // 작업요청이 더 있을 수 있음
        }
        // 힙에 처리할 작업이 있는 경우
        if (!pq.empty()) {
            timer += pq.top().time;
            answer += timer - pq.top().request;
            pq.pop();
        }
        // 처리할 작업이 없는 경우
        else timer = jobs[idx][0]; // 다음 요청이 들어올 수 있게 timer 갱신
    }

    return answer / jobs.size();
}