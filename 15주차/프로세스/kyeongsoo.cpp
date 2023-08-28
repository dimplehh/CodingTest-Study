#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = -1;
    
    queue<vector<int>> q;
    for(int i=0; i < priorities.size(); i++){
        q.push({priorities[i], i});
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    for(int i=0; i < priorities.size(); i++){
        int k = priorities[i];
        while(k != q.front()[0]){
            q.push(q.front());
            q.pop();
        }
        if(q.front()[1] == location)
            return i+1;
        q.pop();
    }
    
    return answer;
}
