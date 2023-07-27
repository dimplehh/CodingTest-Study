#include <string>
#include <vector>
#include <iostream>

using namespace std;

int yaksu[100001];

void yaksuCount(int number) //알아두기
{
    for(int i = 1; i <= number ; i++)
    {
        for(int j = 1; j <= number / i; j++)
        {
            yaksu[i * j]++;
        }
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;
    yaksuCount(number);
    for(int i = 1; i <= number; i++)
    {
        if(yaksu[i] > limit)
            answer += power;
        else
            answer += yaksu[i];
    }
    return answer;
}
