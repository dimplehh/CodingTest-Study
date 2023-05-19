#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector <int>a;
    long long answer = 0;
    while(n / 10 != 0)
    {
        a.push_back(n % 10);
        n = n / 10;
    }
    a.push_back(n % 10);
    sort(a.begin(), a.end());
    for (int i = a.size() - 1; i >= 0; i--)
    {
        answer += a.at(i);
        if (i == 0)
            break;
        answer *= 10;
    }
    return answer;
}
