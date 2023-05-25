#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> temp;
    if(temp.size() == 1)
        answer = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(temp.size() == 0)
            temp.push(s[i]);
        else if(temp.top() == s[i])
            temp.pop();
        else
            temp.push(s[i]);
    }
    if(temp.size() == 0)
        answer = 1;
    return answer;
}
