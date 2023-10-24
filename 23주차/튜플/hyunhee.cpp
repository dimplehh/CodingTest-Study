#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> &a, pair<int, int> &b)
{
    if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> mp;
    int i = 0;
    int now = 0;
    while(s[i])
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            now = i;
            for(int j = i; j < s.size(); j++)
            {
                if(s[j] == ',' || s[j] == '}')
                {
                    mp[stoi(s.substr(now, j))]++;
                    i = j;
                    break;
                }
            }
        }
        else i++;
    }
    vector<pair<int, int>>vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);
    for(auto num:vec)
        answer.push_back(num.first);
    return answer;
}
