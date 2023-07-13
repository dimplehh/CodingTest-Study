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

struct cmp { // �ð� ª�� �ɸ��°� �켱
    bool operator()(job a, job b) {
        return a.time > b.time;
    }
};

int solution(vector<vector<int>> jobs) {

    // �ü������ SJF (Shortest Job First) �˰���� ����
    // ���� ª�� �۾� �켱
    int answer = 0;
    int timer = 0;
    int idx = 0;

    sort(jobs.begin(), jobs.end());
    // ����ð� ������ �켱���� ���� 
    // [[0, 3], [1, 9], [2, 6]]  ��  [[1, 9], [2, 6], [0, 3]]
    priority_queue<job, vector<job>, cmp> pq;

    job j;
    while (idx < jobs.size() || !pq.empty()) {
        // �۾��ð�(timer) ���� ������ �۾� ��û(jobs[idx][0])�� �ִ� ���
        if (idx < jobs.size() && timer >= jobs[idx][0]) {
            j.request = jobs[idx][0];
            j.time = jobs[idx][1];
            idx++;
            pq.push(j);
            continue; // �۾���û�� �� ���� �� ����
        }
        // ���� ó���� �۾��� �ִ� ���
        if (!pq.empty()) {
            timer += pq.top().time;
            answer += timer - pq.top().request;
            pq.pop();
        }
        // ó���� �۾��� ���� ���
        else timer = jobs[idx][0]; // ���� ��û�� ���� �� �ְ� timer ����
    }

    return answer / jobs.size();
}