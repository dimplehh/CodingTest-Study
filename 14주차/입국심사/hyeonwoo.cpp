#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long start = 1;
    long long end = (long long)n * times[times.size() - 1];

    long long cnt, mid;

    while (start <= end) {
        cnt = 0;
        mid = (start + end) / 2;

        // 통과 가능한 사람수 카운트
        for (int i = 0;i < times.size();i++) cnt += mid / times[i];

        // 이분탐색 - start,end 값 재조정
        if (n > cnt) start = mid + 1;
        else {
            if (mid <= end) answer = mid;
            end = mid - 1;
        }
    }

    return answer;
}