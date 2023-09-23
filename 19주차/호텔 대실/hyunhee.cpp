#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int setTime(string time) //string을 받아서 시간을 분 기준으로 int형태로 세팅한다.
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
    priority_queue<int, vector<int> ,greater<int>> cOuts; //오름차순 우선순위큐
    sort(book_time.begin(), book_time.end()); //첫번째 인덱스 기준으로 오름차순정렬
    for(int i = 0; i < book_time.size(); i++)
    {
        int cOutTime = setTime(book_time[i][1]);
        int cInTime = setTime(book_time[i][0]);
        if(!cOuts.empty() && cOuts.top() + 10 <= cInTime)//기존 큐에서 가장 작은checkOut보다 현재 checkIn값이 클 때 -> 그 방에 체크인 가능
            cOuts.pop();
        cOuts.push(cOutTime); //기본은 그냥 push , pop됐을 경우 새로운 값으로 교체
    }
    return cOuts.size();//우선순위큐의 size가 정답이 됨
}
