#include <string>
#include <vector>
#include <iostream>
using namespace std;
char list[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string change(int num, int n)
{
    string result = "";
    while (num / n > 0)
    {
        string temp = result;
        result = list[num % n];
        result += temp;
        num /= n;
    }
    string temp = result;
    result = list[num % n];
    result += temp;
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str="";
    for(int i =0; i <= t * m; i++)
        str += change(i, n);
    for(int i = 0; i < t; i++)
        answer += str[m * i + p - 1];
    return answer;
}
