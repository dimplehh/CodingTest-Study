#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<char, int> expireMap;

// 날짜를 string 벡터로 변환
vector<string> DayStringVector(string _day) {
    vector<string> res;
    string temp = "";
    for (int i = 0;i < _day.length();i++) {
        if (_day[i] == '.' || _day[i] == ' ') { res.push_back(temp); temp = ""; }
        else temp += _day[i];
    }
    res.push_back(temp);
    return res;
}

// 유효기간 map 저장
void SetExipreMap(string term) {
    string termNum;
    for (int i = 2;i < term.length();i++) termNum += term[i];
    expireMap[term[0]] = stoi(termNum);
}

// 날짜를 int 벡터로 변환
vector<int> DayIntVector(vector<string> parsed) {
    vector<int> res;

    // "01", "02" 처럼 앞에 0 있는경우 "1", "2" 로 변환
    if (parsed[1][0] == '0') parsed[1] = parsed[1][1];
    if (parsed[2][0] == '0') parsed[2] = parsed[2][1];

    res.push_back(stoi(parsed[0]));
    res.push_back(stoi(parsed[1]));
    res.push_back(stoi(parsed[2]));

    return res;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<string> parsed;
    vector<int> todayNums, privateNums;
    int todayTotal;
    int privateTotal;
    int diff;

    // 오늘의 날짜를 string vector로 분리 후 int vector 에 담는다
    todayNums = DayIntVector(DayStringVector(today));

    // 유효기간을 map에 등록한다
    for (int i = 0;i < terms.size();i++) SetExipreMap(terms[i]);

    // 개인정보 수만큼 검사
    for (int i = 0;i < privacies.size();i++) {

        parsed = DayStringVector(privacies[i]); // 개인정보 날짜 string vector
        privateNums = DayIntVector(parsed); // 개인정보 날짜 int vector

        // 오늘 날짜와 개인정보 날짜의 day 수를 구한 후, 유효기간 지났을 때 차이값 diff가 0보다 크거나 같으면 만료 -> answer에 push
        todayTotal = todayNums[0] * 28 * 12 + todayNums[1] * 28 + todayNums[2];
        privateTotal = privateNums[0] * 28 * 12 + privateNums[1] * 28 + privateNums[2];
        diff = todayTotal - (privateTotal + expireMap[parsed[3][0]] * 28);
        if (diff >= 0)  answer.push_back(i + 1);
    }

    return answer;
}

int main() {
    solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
}