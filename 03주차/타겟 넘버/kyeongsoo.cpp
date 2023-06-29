#include <string>
#include <vector>

using namespace std;

void DFS(int cnt, int result, vector<int>& numbers, int& target, int& answer){
    if(cnt == numbers.size()){
        if(result == target)
            answer++;
        return;
    }
    
    DFS(cnt+1, result + numbers[cnt], numbers, target, answer);
    DFS(cnt+1, result - numbers[cnt], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(0, 0, numbers, target, answer);
    return answer;
}
