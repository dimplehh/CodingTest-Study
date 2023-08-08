//투포인터

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int setSum(int first, int last)
{
    return ((last + 1) * last / 2 - first * (first - 1)/ 2);
}

int solution(int n) {
    int answer = 1;
    int first = 1; int last = 1;
    if (n == 1) return 1;
    for(int i = 0; i < n; i++)
    {
        int sum = setSum(first, last);
        if(sum < n) last++;
        else if(sum >= n)
        {
            first++;
            if(sum == n)
            {
                answer++;
                last++;
            }
        }
    }
    return answer;
}
