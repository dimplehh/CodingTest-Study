#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> mp;
    for(int i = 0; i < clothes.size(); i++){
        mp[clothes[i][1]]++;
    }
    int answer = 1;
    for (auto i = mp.begin(); i != mp.end(); i++){ //map에서 요소 참조하는 방법
        answer *= (i->second + 1);
    }
    answer -= 1;
    return answer;
}
