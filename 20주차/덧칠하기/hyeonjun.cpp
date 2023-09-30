#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    queue<int> q;
    
    for(int i=0; i< section.size(); i++)
    {
        q.push(section[i]);
    }   
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer++;
        while(cur + m > q.front() && !q.empty())
        {
            q.pop();
        }
    }
    return answer;
}
