#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;


vector<string> split(string input, char delimiter);


vector<string> solution(vector<string> records) {
    vector<string> answer;
    unordered_map<string, string> commandDB = {
        {"Enter" , "님이 들어왔습니다."},
        {"Leave" , "님이 나갔습니다." }
    };

    unordered_map<string, string> userDB;
    vector<vector<string>> logVec;

    for (string record : records) {
        vector<string> str = split(record, ' ');
        if(str[0] == "Enter"){
            userDB[str[1]] = str[2];
            logVec.push_back({ str[0], str[1] });
        }
        else if(str[0] == "Leave"){
            logVec.push_back({ str[0], str[1] });
        }
        else {
            userDB[str[1]] = str[2];
        }
    }

    for (vector<string> log : logVec) {
        string str = userDB[log[1]] + commandDB[log[0]];
        answer.push_back(str);
    }

    return answer;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}
