#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int i = 1; //각 칸 번호 (1부터 시작)
    int j = 0;
    while(i <= n)
    {
        if(i != section[j]) i++; //칸 번호와 칠해야할 번호 비교해서 일치하지 않을때는 칸 하나 옆으로
        else //칸번호와 칠해야할 번호가 일치할 경우
        {
            answer++; //기본적으로 answer 1 증가
            if(i + m <= n) //벽돌을 넘어가지 않을 때
            {
                for(int k = i; k < i + m; k++) //k번동안
                    if(k == section[j]) //칠해야할 번호 있으면
                        j++; //section의 index증가
                i += m; //m만큼 칸 번호 증가
            }
            else break; //벽돌 넘어갈 때 break
        }
    }
    return answer;
}
