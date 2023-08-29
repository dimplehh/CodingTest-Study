#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct process {
    int location;
    int priority;
}process;

struct cmp {
    bool operator()(process a, process b) {
        //if (a.priority == b.priority) return a.location < b.location;
        return a.priority < b.priority;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<process> q; // 프로세스 큐
    priority_queue<process, vector<process>, cmp> processQueue; //  우선순위 큐<위치, 우선순위>
    for (int i = 0;i < priorities.size();i++) {
        process p;
        p.location = i, p.priority = priorities[i];
        processQueue.push(p);
        q.push(p);
    }
    while (!q.empty()) {
        if (q.front().priority != processQueue.top().priority) {
            q.push(q.front());
            q.pop();
        }
        else {
            answer++;
            if (q.front().location == location) break;
            q.pop();
            processQueue.pop();
        }
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1, 1, 9, 1, 1, 1 }, 0);
}