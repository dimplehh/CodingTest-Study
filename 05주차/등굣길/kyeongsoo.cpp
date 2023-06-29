#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
        int dp[101][101] = { 0, };
    dp[1][1] = 1;
    for (auto vec : puddles) {
        dp[vec[0]][vec[1]] = -1;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i == j && i == 1) || dp[i][j] < 0) { continue;}
            x = dp[i - 1][j] >= 0 ? dp[i - 1][j] : 0;
            y = dp[i][j - 1] >= 0 ? dp[i][j-1] : 0;
            dp[i][j] = (x + y) % 1000000007;
        }
    }
    int answer = dp[m][n];
    return answer;
}
