#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {

    // 고민해봐도 잘 모르겠어서 찾아본 결과 dp 써서 해결하는 것 같다
    vector<set<int>> v(8);
    int answer = -1;

    // 처음에 v[0] = { 5 } , v[1] = { 55 } , v[2] = { 555 } 이런 식으로 채운다
    int sum = 0;
    for (int i = 0;i < 8;i++) {
        sum = 10 * sum + N;
        v[i].insert(sum);
    }

    // dp 돌린다
    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < i;j++) {
            for (int x : v[j]) // 파이썬에서 " for x in v[j]: " 와 같다
                for (int y : v[i - j - 1]) { // 파이썬에서 " for y in v[i-j-1]: " 와 같다
                    v[i].insert(x + y);
                    v[i].insert(x - y);
                    v[i].insert(x * y);
                    if (y != 0) v[i].insert(x / y); // 예외처리 안하면 floating point 에러 뜸
                }
        }
        // v[0] = { 5 }
        // v[1] = { 0, 5, 10, 25, 55 }
        // v[2] = { 0, 2, 5, 10, 11, 15, 20, 25, 30 ... }
        if (v[i].find(number) != v[i].end()) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}