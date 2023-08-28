#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> keys;
    for(string km : keymap){
        for(int j = 0; j <km.size(); j++){
            if(keys.find(km[j]) == keys.end() || keys[km[j]] > j+1){
                keys[km[j]] = j+1;
            }
        }
    }
    
    for(string target : targets){
        int sum = 0;
        for(int i = 0; i <target.size(); i++){
            if(keys.find(target[i]) == keys.end()){
                sum = -1;
                break;
            }
            sum += keys[target[i]];
        }
        answer.push_back(sum);
    }
    return answer;
}
