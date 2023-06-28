#include <string>
#include <vector>

using namespace std;
int answer = 0;//전역변수로 선언
int num = 0;
void DFS(vector<int> numbers, int target, int sum, int index){//이 안에서의 변수 크기 변화는 매개변수로 시켜줌
    if(index == numbers.size())//가장 먼저 지금이 끝까지 내려갔는지 확인.재귀 각 실행시마다의 종료 조건만을 설정(index가 끝까지 갔을 때)//index가 더이상 numbers를 참조할 수 없어질 때.
    {
        if(sum == target)
            answer++;
        return;
    }
    DFS(numbers, target, sum + numbers[index] , index + 1);//sum += numbers[index], index += 1
    DFS(numbers, target, sum - numbers[index], index + 1);//sum -= numbers[index], index += 1
}

int solution(vector<int> numbers, int target) {
    cout << num << endl;
    DFS(numbers, target, 0, 0);//main에서 함수 실행 시에는 sum, index가 처음(0)에서 시작하도록 해야함.
    return answer;
}
