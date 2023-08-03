#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    //ÀÌ½Ä
    priority_queue<int, vector<int>, greater<>> s;

    for (int i = 0; i < scoville.size(); i++)
    {
        s.push(scoville[i]);
    }

    int a = 0; int b = 0;

    for (int i = 0; i < scoville.size(); i++)
    {
        if (s.top() >= K)
            return answer;

        a = s.top(); s.pop();
        if (s.empty())
            break;
        b = s.top(); s.pop();

        s.push(a + b * 2);
        answer++;
    }

    return -1;
}

int main()
{
    vector<int> test = { 1, 2, 3, 9, 10, 12 };

    int a = solution(test, 7);

    return a;
}