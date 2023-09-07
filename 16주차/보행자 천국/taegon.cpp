#include <vector>
#include <stdio.h>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<int>> v(m, vector<int>(n, 0));

    int icnt = 1;
    int jcnt = 1;
    for (int i = 0; i < n; i++) {
        if (city_map[0][i] != 1) {
            v[0][i] = 1;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (city_map[i][0] != 1) {
            v[i][0] = 1;
        }
        else {
            break;
        }
    }


    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (city_map[i][j] == 1) {
                v[i][j] = 0;
            }
            else {
                icnt = 1;
                jcnt = 1;
                while (i - icnt >= 0) {
                    if (city_map[i - icnt][j] != 2) {
                        if (city_map[i - icnt][j] == 1) {
                            icnt = -1;
                        }
                        break;
                    }
                    else {
                        icnt++;
                    }
                }
                if (i - icnt >= 0 && icnt != -1)
                    v[i][j] = (v[i][j] % MOD + v[i - icnt][j] % MOD) % MOD;

                while (j - jcnt >= 0) {
                    if (city_map[i][j - jcnt] != 2) {
                        if (city_map[i][j - jcnt] == 1) {
                            jcnt = -1;
                        }
                        break;
                    }
                    else {
                        jcnt++;
                    }
                }
                if (j - jcnt >= 0 && jcnt != -1)
                    v[i][j] = (v[i][j] % MOD + v[i][j - jcnt] % MOD) % MOD;

            }
        }
    }


    answer = v[m - 1][n - 1];
    return answer;
}