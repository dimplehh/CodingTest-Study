#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> termTable;
map<int, tuple<string, string>> privTable;
void init(vector<string> terms, vector<string> privacies)
{
    for(auto term: terms)
    {
        string alp = term.substr(0, term.find(' '));//A,B,C
        string month = term.substr(term.find(' ') + 1);//유효기간
        termTable.insert({alp, stoi(month)});
    }
    int i = 1;
    for(const auto priv:privacies)
    {
        string date = priv.substr(0, priv.find(' '));
        string alp = priv.substr(priv.find(' ') + 1);
        privTable.insert({i, make_tuple(date, alp)});
        i++;
    }
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    init(terms, privacies);
    int tyear = stoi(today.substr(0,4));
    int tmonth = stoi(today.substr(5,2));
    int tday = stoi(today.substr(8));
    for(auto priv:privTable)
    {
        int year = stoi(get<0>(priv.second).substr(0,4));
        int month = stoi(get<0>(priv.second).substr(5, 2));
        int day = stoi(get<0>(priv.second).substr(8));
        month += termTable[get<1>(priv.second)];
        day--;
        if(day == 0)
        {
            day = 28;
            month--;
        }
        if(month > 12)
        {
            year++;
            month -= 12;
        }
        if((tyear - year) * 28 * 12 + (tmonth - month) * 28 + (tday - day) > 0)
            answer.push_back(priv.first);
    }
    return answer;
}
