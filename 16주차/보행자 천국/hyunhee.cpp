
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int right[501][501] = {0,};
    int down[501][501] = {0,};
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j == 1)
            {
                right[i][j] = 1;
                down[i][j] = 1;
            }
            else
            {
                if(city_map[i - 1][j - 1] == 0)
                {
                    right[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
                    down[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
                }
                else if(city_map[i - 1][j - 1] == 1)
                {
                    right[i][j] = 0;
                    down[i][j] = 0;
                }
                else
                {
                    right[i][j] = right[i][j - 1] % MOD;
                    down[i][j] = down[i - 1][j] % MOD;
                }
            }
        }
    }
    return down[m][n] % MOD;
}
