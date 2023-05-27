#include <string>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> temp;
    queue<char> que;
    for (int j = 0; j < s.length(); j++)
        que.push(s[j]);
    for (int j = 0; j < s.length(); j++)
    {
        for(int i= 0; i <s.length(); i++)
        {
            if(temp.empty())
                temp.push(s[i]);
            else
            {
                if(temp.top() == '[' && s[i] == ']')
                    temp.pop();
                else if(temp.top() == '{' && s[i] == '}')
                    temp.pop();
                else if(temp.top() == '(' && s[i] == ')')
                    temp.pop();
                else
                    temp.push(s[i]);
            }
        }
        if(temp.size() == 0)
            answer += 1;
        else
            while( !temp.empty() ) temp.pop();
        for (int j = 0; j < s.length(); j++)
            que.push(s[j]);
        que.push(que.front());
        que.pop();
        for (int j = 0; j < s.length(); j++)
        {
            s[j] = que.front();
            que.pop();
        }
    }
    return answer;
}
