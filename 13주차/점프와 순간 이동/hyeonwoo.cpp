#include <iostream>
using namespace std;

// 1 ¡æ 1
// 2 ¡æ 1
// 3 ¡æ 2
// 4 ¡æ 1
// 5 ¡æ 2
// 6 ¡æ 2
// 7 ¡æ 3
// 8 ¡æ 1

int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        int temp = 1;
        while (temp * 2 <= n) temp *= 2;
        n -= temp;
        ans++;
    }

    return ans;
}