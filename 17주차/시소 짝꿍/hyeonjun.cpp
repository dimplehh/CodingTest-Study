#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<long long> mp(1001, 0);
    
    for(int i=0; i<weights.size(); i++)
        mp[weights[i]]++;
    
    for(int i=0; i<weights.size(); i++)
    {
        long long other;
        // 2로 나누어진다면 2 : 3에 속하는 경우가 있는지 확인
        if(weights[i] % 2 == 0)
        {
            other = (weights[i] / 2 ) * 3;
            if(other <= 1000)
                answer += mp[other];
        }
        // 3으로 나누어진다면 3 : 4에 속하는 경우가 있는지 확인
        if(weights[i] % 3 == 0)
        {
            other = (weights[i] / 3) * 4;
            
            if(other <= 1000)
                answer += mp[other];
        }
        // 2 : 4 속하는 경우 확인
        other = weights[i] * 2;
        if(other <= 1000)
            answer += mp[other];
    }
    
    // weights가 같을 때 같은 수만큼 마주 볼 수 있음
    for(int i = 100 ; i<= 1000; i++)
    {
        if(mp[i] >= 2)
        {
            answer += (long long)(mp[i] * (mp[i] - 1)) / 2;
        }
    }
    return answer;
}
