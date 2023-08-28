#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;


vector<string> Split(string str, char delimiter);


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<string> ymd = Split(today, '.');
    int todayYear = stoi(ymd[0]) - 2000;
    int todayMonth = stoi(ymd[1]) -1;
    int todayDay = stoi(ymd[2]) - 1;
    int todays = todayYear *(12 * 28) + todayMonth * 28 + todayDay;
    
    map<string, int> td;
    
    for(string term : terms){
        vector<string> tv = Split(term, ' ');
        td[tv[0]] = stoi(tv[1]);
    }
    
    for(int i = 0; i < privacies.size(); i++){
        
        string privacy = privacies[i];
        vector<string> pv = Split(privacy, ' ');
        string day = pv[0];
        
        int month = td[pv[1]];
        
        int tYear = month/12;
        int tMonth = month%12;
        
        int dayYear = stoi(string(day, 0, 4)) + tYear;
        int dayMonth = stoi(string(day, 5, 7)) + tMonth;
        int dayDay = stoi(string(day, 8, 10)) - 1;
        
        dayYear-= 2000;
        dayMonth--;
        dayDay--;
        
        int days = dayYear *(12 * 28) + dayMonth * 28 + dayDay;
        if(days < todays){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}

vector<string> Split(string input, char delimiter){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, delimiter)){
        answer.push_back(temp);
    }
    return answer;
}
