
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min = 1;
    long long max = (long long)*min_element(times.begin(), times.end()) * n;
    long long mid;
    long long sum;

    while(min <= max)
    {
        mid = (min + max) / 2; //return값
        sum = 0; //통과하는 사람 수
        for(int i = 0; i < times.size() ;i++)
        {
            sum += mid / times[i];
        }
        if(sum >= n)//6명이 통과해야하는건데 7명이 통과하면
        {
            max = mid - 1;//더 적게통과해야 하므로 max가 작아져야함
            answer = mid;
        }
        else
            min = mid + 1;
    }
    return answer;
}
