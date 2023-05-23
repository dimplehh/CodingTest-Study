#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    vector <char> temp;
    for (int i = 0; i< s.length(); i++)
        temp.push_back(s[i]); //temp 구현
    while(1)
    {
        if(temp.size() == 1)
            return 0;
        else if(temp.size() == 2)
            if(temp[0] == temp[1])
                return 1;
            else
                return 0;
        else
        {
            int stat = 0;
            for(int i = 0; i < temp.size() - 1;i++)
            {
                if(temp[i] == temp[i + 1])
                {
                    temp.erase(temp.begin() + i);
                    temp.erase(temp.begin() + i);
                    stat = 1;
                    break;
                }
            }
            if(stat == 0)
                return 0;
        }
    }
    return answer;
}
