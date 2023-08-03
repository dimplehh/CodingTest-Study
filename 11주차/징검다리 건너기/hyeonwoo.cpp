#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이전에 순차탐색으로 해봤는데 시간초과 발생

// 메모 :
// *max_element(arr.begin(), arr.end())  ->  배열의 최댓값 리턴
// *min_element(arr.begin(), arr.end())  ->  배열의 최솟값 리턴


bool IsPossible(int mid, vector<int> stones, int k) {
    int cnt = 0;
    for (int i = 0;i < stones.size();i++) {
        if (stones[i] - mid <= 0) cnt++;
        else cnt = 0;
        if (cnt >= k) return false;
    }
    return true;
}


int solution(vector<int> stones, int k) {
    int start = 1; // 다리 건널 수 있는 최소 인원 = 1
    int end = *max_element(stones.begin(), stones.end()); // 최대로 건널 수 있는 사람 수 = 배열 최대값

    while (start <= end) {
        int answer = 0;
        int mid = (start + end) / 2;
        if (!IsPossible(mid, stones, k)) end = mid - 1;// 못 건너는 경우
        else start = mid + 1;
    }
    return start;
}