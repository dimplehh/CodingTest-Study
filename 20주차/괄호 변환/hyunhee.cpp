#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string answer = "";

bool check_right(string &str)
{
    stack<int> st;
    for(int i = 0; i < str.length(); i++)
    {
        if(!st.empty() && st.top()== '(' && str[i] == ')') st.pop();
        else st.push(str[i]);
    }
    return st.empty();
}

string new_u(string str)
{
    string new_str = "";
    if(str.length() <= 2)
        return "";
    else str = str.substr(1, str.length() - 2);
    for(int i = 0; i <str.length(); i++)
    {
        if(str[i] == '(') new_str += ')';
        else if(str[i] == ')') new_str += '(';
    }
    return new_str;
}

void devide_uv(string str, string &u, string &v)
{
    int num1 = 0,num2 = 0,i = 0,j = 0;
    for (i = 0; i < str.length(); i++)
    {
        if(str[i] == '(') num1++;
        else if(str[i] == ')') num2++;
        u += str[i];
        if(num1 != 0 && num1 == num2)
            break;
    }
    for(int j = i + 1; j <str.length(); j++) v += str[j];
}

string solution(string p) {//solution이 재귀가 되어야 함
    if(p == "") return ""; //1단계
    if(check_right(p)) return p; //올바른 값이면 바로 return
    string u,v;
    devide_uv(p, u, v);//2단계 : 분리
    answer = (check_right(u)) ? u + solution(v) : "(" + solution(v) + ")" + new_u(u);
    //3단계 : 올바른 괄호 문자열일 경우 u + solution(v)
    //4단계 : 올바른 괄호 문자열이 아닌 경우 "(" + solution(v) + ")" + new_u(u)
    return answer;
}
