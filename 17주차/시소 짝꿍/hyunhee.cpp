#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, long long> mp; //m.second * (m.second - 1) / 2이 int범위 넘을 수 있으므로 second 값은 long long
    for(int i = 0; i < weights.size(); i++)
        mp[weights[i]]++;
    for (auto m:mp)
        if(m.second >= 2)
            answer += m.second * (m.second - 1) / 2;//같은 값이 나오는 경우를 우선 더해줌
    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());//중복 제거
    int pivot = 0;
    for(int i = 1; i < weights.size(); i++)
    {
        for(int j = pivot; j < i; j++)
        {
            if(weights[i] * 2 == weights[j] * 4 
               || weights[i] * 2 == weights[j] * 3 
               || weights[i] * 3 == weights[j] * 4)
            {
                answer += mp[weights[i]] * mp[weights[j]];
            }
        }
        if(weights[pivot] * 4 < weights[i] * 2)
            pivot++;
    }
    return answer;
}
