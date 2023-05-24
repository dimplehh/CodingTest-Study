#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while(n != 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), greater<>());
    int x = 1;
    for(int i=v.size() - 1; i>=0;i--)
    {
        answer += v[i] * x;
        x *= 10;
    }
    return answer;
}
