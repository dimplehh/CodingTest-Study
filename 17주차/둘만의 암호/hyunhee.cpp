#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i = 0; i < s.size(); i++)
    {
        int j = 0;
        while(j < index)
        {
            s[i]++;
            if(s[i] > 'z') s[i] = s[i] + 'a' - 'z' - 1; //z보다 큰 s[i]를 바꿔주는 게 find보다 먼저가 되어야 함
            if(skip.find(s[i]) == string::npos)j++;
        }
        answer += s[i];
    }
    return answer;
}
