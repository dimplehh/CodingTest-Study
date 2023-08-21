#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min = 1;
    long long max = (long long)*max_element(times.begin(), times.end()) * n; //왜?
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
