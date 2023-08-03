#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> command; // 입력한 커맨드, [0]=Enter [1]=uid1234 [2]=Muzi
    vector<pair<string, bool>> uid_command; // uid 와 command 저장
    unordered_map<string, string> dict; // user id 대로 name을 저장하는 딕셔너리

    string temp;

    for (int i = 0;i < record.size();i++) {
        // 입력한 명령어 문자열 구분
        command.clear();
        for (int j = 0;j < record[i].size();j++) {
            if (record[i][j] == ' ') { command.push_back(temp); temp = ""; }
            else temp += record[i][j];
        }
        command.push_back(temp); temp = "";

        // 명령어대로 uid_command 저장 및 딕셔너리 갱신
        // 이때 Enter 된 uid 는 true로 저장
        // Leave 된 uid 는 false로 저장
        if (command[0] == "Enter") { uid_command.push_back(make_pair(command[1], true)); dict[command[1]] = command[2]; }
        else if (command[0] == "Leave") uid_command.push_back(make_pair(command[1], false));
        else if (command[0] == "Change") dict[command[1]] = command[2];
    }

    // uid_commmand에 담긴 값 answer 에 저장
    for (int i = 0;i < uid_command.size();i++) {
        pair<string, bool> item;
        item = uid_command[i];
        if (item.second) answer.push_back(dict[item.first] + "님이 들어왔습니다.");
        else answer.push_back(dict[item.first] + "님이 나갔습니다.");
    }

    return answer;
}