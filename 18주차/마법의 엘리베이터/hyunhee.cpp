#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solution(int storey) {
    int answer = 0;
    bool lastAdd = false;
    string str = to_string(storey);
    for(int i = str.length() - 1; i >= 0;i--)
    {
        if(str[i] >= '6' || (i >= 1 && str[i - 1] >= '5' && str[i] == '5'))
        {
            if(i == 0) lastAdd = true;
            answer += 10 - (str[i] - '0');
            if(i >= 1 && str[i - 1] == '9')
            {
                int j = i - 1;
                while(j >= 1 && str[j] == '9')
                    str[j--] = '0';
                str[j] += 1;
            }
            else if(i >= 1) str[i - 1] += 1;
        }
        else answer += (str[i] - '0');
        str[i] = '0';
    }
    
    if(lastAdd) answer += 1;
    return answer;
}
