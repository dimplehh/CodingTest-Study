#include <string>
#include <vector>
#include <iostream>
#include <map>
#define INF 1000
#define MIN(x,y)(x<y)?x:y
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> mp;
    for (int i ='A'-'A'; i <= 'Z'-'A';i++)
        mp['A' + i] = INF;
    for(auto key: keymap)
    {
        for(int i = 0; i < key.size(); i++)
            mp[key[i]] = MIN(mp[key[i]],i + 1);
    }
    for(auto target:targets)
    {
        int temp = 0;
        for(int i = 0; i < target.size(); i++)
            temp += mp[target[i]];
        if(temp >= INF)
            temp = -1;
        answer.push_back(temp);
    }
    return answer;
}
