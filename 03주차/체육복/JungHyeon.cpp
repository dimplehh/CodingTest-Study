#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int idx = 0;
    vector<int> ShirtCount(n, 1);
  
    for (auto& lostStudent : lost) { ShirtCount[lostStudent - 1] -= 1; }
    for (auto& reserveStudent : reserve) { ShirtCount[reserveStudent - 1] += 1; }

    for (auto& isZero : ShirtCount) {
        if (isZero == 0) {
            if (idx != 0 && ShirtCount[idx - 1] == 2) {
                ShirtCount[idx - 1] -= 1;
                ShirtCount[idx] += 1;
            }
            else if (idx < ShirtCount.size() && ShirtCount[idx + 1] == 2) {
                ShirtCount[idx + 1] -= 1;
                ShirtCount[idx] += 1;
            }
        }
        idx++;
    }
    answer = ShirtCount.size() - count(ShirtCount.begin(), ShirtCount.end(), 0);
    return answer;
}
