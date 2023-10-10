#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;
vector<int> apeach;
vector<int> lion;
vector<int> maxRes; // 정답 배열
int maxDiff = 0; // 최대 점수차

// (dpt : 깊이, asc : 현재 어피치 점수, lsc : 현재 라이언 점수, n : 현재 사용한 화살의 개수)
void dfs(int dpt, int asc, int lsc, int n){
    if(dpt==11) {
        if(lsc <= asc) return;//어피치가 이겼을 경우 return하여 -1 반환
        lion[10] += N-n; // 남은 화살 0점에 몰아주기
        if(lsc - asc > maxDiff) {//정답 배열 갱신
            maxRes = lion;
            maxDiff = lsc - asc;//최대 차이 갱신
        } else if(lsc - asc == maxDiff) { // 점수가 같은 경우, 낮은 점수에 많이 맞힌 경우가 정답
            for(int i=10; i>=0; i--){
                if(lion[i]==maxRes[i]) continue;
                else {
                    if(lion[i] > maxRes[i])
                        maxRes = lion;
                    break;
                }
            }
        }
        return;
    }
    // 라이언이 점수(10-dpt)를 획득하는 경우
    int next = apeach[dpt] + 1;
    if(n + next <= N) { // if문 만족할 경우
        int nasc = asc; // 다음 깊이에서의 어피치 점수
        int nlsc = lsc + 10 - dpt; // 다음 깊이에서의 라이언 점수(next+n, nasc, nlsc-> 축적되는 값)
        if(apeach[dpt]!=0) nasc -= (10-dpt);
        lion.push_back(next);
        dfs(dpt+1, nasc, nlsc, n + next);
        lion.pop_back(); // 백트래킹
    }
    lion.push_back(0);//기본실행문
    dfs(dpt+1, asc, lsc, n);//깊이만 갱신, 나머지는 갱신하지 않은 값 넣음
    lion.pop_back(); // 백트래킹
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;
    int aSum = 0;
    for(int i=0; i<info.size(); i++){ if(info[i] > 0) {aSum += (10-i);}}//어피치 초기점수 세팅
    dfs(0, aSum, 0, 0);
    if(maxDiff==0) maxRes.push_back(-1);
    return maxRes;
}
