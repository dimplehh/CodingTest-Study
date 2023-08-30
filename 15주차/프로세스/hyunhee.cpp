#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct process {
    int prio;
    int idx;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<process> q;
    for(int i=0;i<priorities.size();i++) {
        q.push({priorities[i],i});
    }
    int max = *max_element(priorities.begin(), priorities.end());
    while(!q.empty()) {
        if(q.front().prio==*max_element(priorities.begin(), priorities.end())) {
            answer++;
            int index = q.front().idx;
            if(q.front().idx==location) break;
            q.pop();
            priorities[index] = 0;
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}
