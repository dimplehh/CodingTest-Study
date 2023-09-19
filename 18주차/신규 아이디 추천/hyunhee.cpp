#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void erase(string &new_id)
{
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());//1,2단계
}

string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.size(); i++)
        if('A' <= new_id[i] && new_id[i] <= 'Z')
            new_id[i] -= ('A' - 'a');
        else if('a' <= new_id[i] && new_id[i] <= 'z'
                || '0' <= new_id[i] && new_id[i] <= '9'
               || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            continue;
        else new_id[i] = ' ';
    erase(new_id);//1,2단계

    for(int i = 0; i < new_id.size(); i++)
        if(new_id[i] == '.')
            while(i + 1 <= new_id.size() && new_id[i + 1] == '.')
                new_id[i++ + 1] = ' ';
    erase(new_id);//3단계

    int temp[] = {0, (int)new_id.size() - 1};
    for (int i = 0; i < 2; i++)
        if(new_id[i] == '.') new_id[temp[i]] = ' ';
    erase(new_id);//4단계

    if(new_id.size() == 0) new_id += 'a';
    if(new_id.size() >= 16) new_id.erase(new_id.begin() + 15, new_id.end());
    if(new_id[new_id.size() - 1] == '.') new_id [new_id.size() - 1] = ' ';
    erase(new_id);//5, 6단계

    if(new_id.size() <= 2)
        while(new_id.size() < 3)
            new_id += new_id[new_id.size() - 1];//7단계

    return new_id;
}
