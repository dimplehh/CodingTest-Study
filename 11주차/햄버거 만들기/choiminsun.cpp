#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    string str = ""; //주어진 백터 str로 변환
    for (int i : ingredient)
    {
        char c = i + '0'; 
        str += c; 
    }

    int start = 0; //탐색 시작점
    while (true)
    {
        //탐색
        long pos = str.find("1231", start);

        if (pos == std::string::npos) //없으면 루프문 나감
            break;
        else //있으면 버거 지우기
        {
            str.erase(pos, 4);
            answer++;
        }

        //탐색 지점 세팅
        if (pos > 2) //2 이하면 처음부터
            start = pos - 3; //아니면 찾은 위치 - 3부터
    }

    return answer;
}