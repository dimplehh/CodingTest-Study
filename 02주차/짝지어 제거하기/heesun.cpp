#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> charStack;
    
    for (int i=0; i<s.length(); i++)
    {
        if (charStack.empty() || charStack.top() != s[i])
        {
            charStack.push(s[i]);
        }            
        
        else if (charStack.top() == s[i])
        {
            charStack.pop();
        }
            
    }
    
    if (charStack.empty())
    {
        return 1;
    }        
    return 0;
}