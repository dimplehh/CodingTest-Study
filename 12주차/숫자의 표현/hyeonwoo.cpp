#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;

    for (int i = 1;i <= n / 2;i++) {
        sum = 0;
        for (int j = i;j < n;j++) {
            sum += j;
            if (sum > n) break;
            else if (sum == n) { answer++; break; }
        }
    }
    answer++;

    return answer;
}