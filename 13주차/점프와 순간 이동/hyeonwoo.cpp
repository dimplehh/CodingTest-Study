#include <iostream>
using namespace std;

// 1 �� 1
// 2 �� 1
// 3 �� 2
// 4 �� 1
// 5 �� 2
// 6 �� 2
// 7 �� 3
// 8 �� 1

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