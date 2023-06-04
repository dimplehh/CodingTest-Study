#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    answer = participant.back();
    for (int i = 0; i < completion.size(); i++)
    {
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

