#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer;
void DFS(int x, int y, int n, int count){
    if(x == y)
    {
        if(answer == 0 || count < answer)
        {
            answer = count;
        }
        return ;
    }
    else if(answer != 0 && count > answer)
        return;
    else if(x > y)
        return;
    DFS(x * 3, y, n, count + 1);
    DFS(x * 2, y, n, count + 1);
    DFS(x + n, y, n, count + 1);
}

int solution(int x, int y, int n) {
    answer = 0;
    DFS(x, y, n, 0);
    if(x != y && answer == 0)
        answer = -1;
    return answer;
}
