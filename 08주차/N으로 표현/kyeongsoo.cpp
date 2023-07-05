//1. DP 및 BFS - 실패
//음수의 결과값을 dp로 저장하지 못함
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
const int MAX = 100000000;

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    int dp[MAX];
    fill_n(dp, MAX, 9);
    queue<int> q;
    int k = N;
    for(int i = 1; i <= 7; i++){
        dp[k] = i;
        q.push(k);
        k = k*10+ N;
    }
    int arr[4];
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(dp[x]> 8 || x<= 0)
            continue;
        if(x == number)
            return dp[x];
        arr[0] = x+N < MAX ? x+N : MAX-1;
        arr[1] = x-N > 0 ? x-N : 1;
        arr[2] = x*N < MAX ? x*N : MAX-1;
        arr[3] = x/N;
        
        for(int i = 0; i < 4; i++){
            if(i == 3 && x%N != 0)
                continue;
            if(dp[arr[i]] > dp[x]+1){
                dp[arr[i]] = dp[x]+1;
                q.push(arr[i]);
            }
        }
    }

    return -1;
}


/**
2. DP + 집합으로 풀이
숫자를 사용한 횟수별 결괏값을 각각 저장
현재 찾는 횟수보다 낮은 횟수별 결괏값끼리 사칙연산을 실시하여 현재 횟수의 결괏값을 저장
ex) 3개 숫자를 쓴 결괏값은 1개 숫자를 쓴 결괏값들과 3개 숫자를 쓴 결괏값들끼리의 사칙연산 + 2개 숫자를 쓴 결괏값들끼리의 사칙연산으로 이루어져 있다.
3개 이상의 조합은 2개의 조합에 포함되므로 필요 없다.
**/
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    set<int> dp[9];
    int k = 0;
    for(int i = 1; i < 9; i++){
        k = k *10 + N;
        dp[i].insert(k);
    }
     
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j < i; j++){
            for(int a : dp[j]){
                for(int b : dp[i - j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b != 0 && a%b == 0)
                        dp[i].insert(a/b);
                }
            }
        }
        if(dp[i].find(number) != dp[i].end())
            return i;
    }
    return -1;
}
