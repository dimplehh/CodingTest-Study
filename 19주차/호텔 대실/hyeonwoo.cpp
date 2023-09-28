#include <string>
#include <vector>
#include <iostream>

#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

int time_stoi(string _time) {
    string targetChar;
    int res = 0;

    targetChar = _time[0];
    targetChar += _time[1];
    res += stoi(targetChar) * 100;
    targetChar = _time[3];
    targetChar += _time[4];
    res += stoi(targetChar);

    return res;
}

int solution(vector<vector<string>> book_time) {
    int roomCnt[2401] = { 0, };
    int answer = 0;

    for (int i = 0;i < book_time.size();i++) {
        int start = time_stoi(book_time[i][0]);
        int end = time_stoi(book_time[i][1]) + 10;
        if (end % 100 >= 60) end += 40;

        for (int j = start;j < end;j++) roomCnt[j] += 1;
    }
    for (int i = 0;i < 2400;i++) {
        answer = MAX(roomCnt[i], answer);
    }

    //cout << answer;
    return answer;
}