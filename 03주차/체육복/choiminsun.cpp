#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size(); //안 잃어버렸으면 본인 거 입기

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int l = 0; //lost의 인덱스
    int r = 0; //reserve의 인덱스

    for (; l < lost.size(); l++)
    {
        for (; r < reserve.size(); r++)
        {
            if (reserve[r] < lost[l] - 1) //1. 나보다 작으면 아무도 못 입어
                continue;
            else if ((reserve[r] >= (lost[l] - 1)) && (reserve[r] <= (lost[l] + 1))) //2. 입을 수 있는 체육복이 있긴한데
            {
                //1. 나보다 작은 사이즈 -> 다음 사이즈가 내 건 아닌지.
                if (reserve[r] == lost[l] - 1)
                {
                    if (r + 1 < reserve.size() && reserve[r + 1] == lost[l])
                        continue;
                }
                //2. 나랑 같음 -> 걍 입어
                //3. 나보다 큰 사이즈 -> 내 다음 친구 사이즈는 아닌지.
                if (reserve[r] == lost[l] + 1)
                {
                    if (l + 1 < lost.size() && lost[l + 1] == reserve[r])
                        break;
                }
                if ((l + 1 < lost.size()) && (reserve[r] == lost[l + 1]))
                {
                    break;
                }
                answer++;
                r++;
            }
            break;
        }
    }
    return answer;
}