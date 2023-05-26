#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
bool ck_str(queue<char> sq)
{
    stack<char> sta;
    int len = sq.size();
    for(int i=0; i<len; i++)
    {
        char c = sq.front();
        sq.pop();
        if(sta.empty())
            sta.push(c);
        else
        {
            if((sta.top() == '[' && c == ']' )|| (sta.top() == '{' && c == '}')
              || sta.top() == '(' && c == ')')
                sta.pop();
            else
                sta.push(c);
        }
    }
    if(sta.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    queue<char> q;
    for(int i=0; i<s.length(); i++)
        q.push(s[i]);
    string tmp;
    for(int i=0; i< s.length(); i++)
    {   
        if(ck_str(q))
            answer++;
        char c = q.front();
        q.pop();
        q.push(c);
    }
    return answer;
}
