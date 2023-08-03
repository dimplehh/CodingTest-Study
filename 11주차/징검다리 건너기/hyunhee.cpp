//다른 알고리즘 어떤것이 가능할까
#include <string>
#include <vector>
using namespace std;
bool check(int n, const vector<int>& stones, int k) {
    int cur = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - n <= 0)
            cur++;
        else
            cur = 0;
        if (cur >= k)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    long long left = 1;
    long long right = 200000000;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, stones, k))
            left = mid + 1;//최대를 구하고 싶으면 left를 옮겨라
        else
            right = mid - 1;//최소를 구하고 싶으면 right를 옮겨라
    }
    return left;//그럼 left가 정답일 것이다.
}
