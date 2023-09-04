#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string lst[4] = {"aya", "ye", "woo", "ma"};
    string temp = "";
    int length;
    for(auto babble : babbling)
    {
        length = 0;
        temp = "";
        for(int i = 0; i < babble.size() ; i++)// "ayaye"
        {
            for(int j = 0; j < 4; j ++)//lst[0] ~lst[3]
            {
                if(babble.substr(i, lst[j].size()) == lst[j]) 
                {
                    if(temp == babble.substr(i, lst[j].size()))
                        break;
                    length += lst[j].size();
                    temp = lst[j];
                    i += lst[j].size() - 1; // i + lst[j].size() 부터 다시 검토
                }
            }
        }
        if(length == babble.size())
            answer++;
    }
    return answer;
}
