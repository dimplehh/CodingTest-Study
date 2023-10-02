#include <string>
#include <vector>
#include <stack>

using namespace std;

bool ckStr(string p)
{
    stack<char> s;
    
    for(int i=0; i<p.length(); i++)
    {
        if(p[i] == '(')
            s.push('(');
        else
        {
            if(s.empty())
                return false;
            else
                s.pop();
        }
    }
    
    if(s.empty())
        return true;
    else
        return false;
}
string solution(string p) {
    string answer = "";
    string u = "", v = "";
    
    int cnt1 = 0, cnt2 =0;
    
    if(p == "")
        return answer;
    
    for(int i=0; i<p.length(); i++)
    {
        if(p[i] == '(')
            cnt1++;
        else if(p[i] == ')')
            cnt2++;
        
        if(cnt1 == cnt2)
        {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(ckStr(u))
    {
        v = solution(v);
        answer = u + v;
        return answer;
    }
    else
    {
        answer += '(';
        answer += solution(v);
        answer += ')';
        
        u.erase(0, 1);
        u.erase(u.length() - 1 ,1);
        for(int i=0; i<u.length(); i++)
        {
            if(u[i] == '(')
                answer += ')';
            else
                answer += '(';
        }
    }
    
    
    
    return answer;
}
