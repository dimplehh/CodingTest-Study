#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 100,180,360,100,270
// sort, (정렬하는 이유? - for문 돌릴 때 1:1, 2:3, 1:2, 3:4 인지 검사하기 위함, 따라서 크기순으로 정렬되어야 됨)
// 100 100 180 270 360

long long solution(vector<int> weights) {
    long long answer = 0;

    sort(weights.begin(), weights.end());

    map<int, int> dict;

    for (auto i : weights) {
        if (dict[i * 1]) answer += dict[i * 1];
        // 퍼센트 연산 해주는 이유? 예를 들어, 2:3의 경우, 66:100 도 인정되기 때문에
        if (i % 3 == 0 && dict[(i * 2) / 3]) answer += dict[(i * 2) / 3];
        if (i % 2 == 0 && dict[(i * 1) / 2]) answer += dict[(i * 1) / 2];
        if (i % 4 == 0 && dict[(i * 3) / 4]) answer += dict[(i * 3) / 4];
        dict[i]++;
    }

    return answer;
}