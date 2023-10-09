#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i <  nums.size(); i++) 
        mp[nums[i]]++;
    for(auto iter = mp.begin();iter != mp.end(); iter++)
    {
        if(iter->second >= 1) answer++;
        if(answer == nums.size() / 2) break;
    }
    return answer;
}
