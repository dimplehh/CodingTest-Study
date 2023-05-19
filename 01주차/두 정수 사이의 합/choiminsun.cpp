//2023.05.10
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;

    //1. a가 b보다 클 경우
    if (a > b)
    {
        for (int i = b; i <= a; i++)
        {
            answer += i;
        }
    }
    //2. a가 b보다 작거나 같을 경우
    else
    {
        for (int i = a; i <= b; i++)
        {
            answer += i;
        }
    }

    return answer;
}