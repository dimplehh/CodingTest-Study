#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> table;
    for(auto str : record)
    {
        string order = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);
        string uid = str.substr(0, str.find(' '));
        if(order == "Enter" || order == "Change")
            table[uid] = str.substr(str.find(' ') + 1);
    }
    for (auto str : record)
    {
        string order = str.substr(0, str.find(' '));
        str = str.substr(str.find(' ') + 1);
        string uid = str.substr(0, str.find(' '));
        if(order == "Enter")
            answer.push_back(table[uid] + "님이 들어왔습니다.");
        else if(order == "Leave")
            answer.push_back(table[uid] +"님이 나갔습니다.");
    }
    return answer;
}
