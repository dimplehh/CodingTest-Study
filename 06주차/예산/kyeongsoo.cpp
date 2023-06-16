#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//탐욕 알고리즘
int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    for(int i : d){
        sum += i;
        if(sum > budget)
            break;
        answer++;
    }
    
    return answer;
}
