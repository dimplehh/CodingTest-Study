#include <string>
#include <vector>
#include <iostream>
#define INF 999
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;

int alphaMoves[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
int moveCounts[21];
string initalName[21];

int solution(string name) {
    int answer = 0;             // 위아래로 움직이는 횟수
    int minMoves = name.size() - 1;   // 좌우로 움직이는 횟수

    // 가장 처음(왼쪽) 위치에서 오른쪽으로 이동 ( name[0] -> name[1] )
    for (int i = 0;i < name.size();i++) {
        answer += alphaMoves[name[i] - 'A'];

        // 다음 위치가 'A'인 경우, 정방향/역방향 비교
        // J J A A A A Z Z
        // 2번째 J에서 1번째 Z로 이동할때 이동횟수
        //      - 진행방향 그대로 이동시 : temp - i
        //      - 역방향 이동시 : i + name.size() - next
        int next = i + 1;
        while (name[next] == 'A' && next < name.size()) next++;

        // 이동하는 수가 적은 방향의 이동횟수로 갱신
        int left = i;
        int right = name.size() - next;
        minMoves = MIN(minMoves, left + right + MIN(left, right));
    }

    cout << answer + minMoves;

    return answer + minMoves;
}

int main() {
    solution("JEROEN");
}