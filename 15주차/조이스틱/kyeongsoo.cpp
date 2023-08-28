#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int min_move = len - 1;

    for (int i = 0; i < len; ++i) {
        // 위 아래 조작 중 더 작은 횟수 선택
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // A 아닌 문자를 만나면 커서 이동을 고려하여 최소 이동 횟수 갱신
        // A 아닌 문자를 만난다 -> 처음 위치에서 현재 위치 다음 뒤로 가서 A 아닌 문자 위치 = A 아닌 모든 문자를 방문한다. 
        int next_idx = i + 1;
        while (next_idx < len && name[next_idx] == 'A')
            next_idx++;
        //i + len - next_idx : 뒤로 갈 경우 현재 위치(i)와 A가 아닌 문자의 위치(next_idx) 사이의 거리
        //min(i, len - next_idx) : 처음 위치에서 i로 먼저갈지, next_idx로 먼저 갈지 최단거리 확인
        min_move = min(min_move, i + len - next_idx + min(i, len - next_idx));
        cout << min_move << endl;
    }
    
    answer += min_move;
    return answer;
}
