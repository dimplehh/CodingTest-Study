#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string input, char delimiter);

vector<int> solution(vector<string> infos, vector<string> querys) {
    vector<int> answer;
    unordered_map<string, vector<int>> map;
    for (string info : infos) {
        vector<string> str = split(info, ' ');
        for (int i = 0; i < 16; i++) {
            string tmp = "";
            for (int j = 0; j < 4; j++) {
                tmp += (i & (1 << j)) ? str[j] : "-";
            }
            map[tmp].push_back(stoi(str.back()));
        }
    }
    for (auto& itr : map) { 
        sort(itr.second.begin(), itr.second.end()); 
    }

    for (string query : querys) {
        vector<string> str = split(query, ' ');
        string tmp = str[0] + str[2] + str[4] + str[6];
        int score = stoi(str.back());

        vector<int> res = map[tmp];
        int cnt = res.end() - lower_bound(res.begin(), res.end(), score);
        answer.push_back(cnt);
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
