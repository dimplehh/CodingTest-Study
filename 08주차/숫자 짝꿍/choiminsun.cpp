#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    vector<int> count(10, 0);

    for (char c : X) //X 탐색
    {
        int i = c - '0';

        count[i]++;
    }

    for (char c : Y)
    {
        int i = c - '0';

        if (count[i] > 0) //X에 있었다면 추가
        {
            count[i]--;
            answer += c;
        }
    }

    sort(answer.begin(), answer.end(), greater<>());

    int i = 0;
    for (; i < answer.length() - 1; i++)
    {
        if (answer[i] != '0')
            break;
    }

    if (answer == "")
        return "-1";

    return answer.substr(i);
}