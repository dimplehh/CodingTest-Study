#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int money = budget;
    int cnt = 0;
    for (int i = 0;i < d.size();i++) {
        if (money <= d[i]) return cnt;
        money -= d[i];
        cnt++;
    }
    return cnt;
}