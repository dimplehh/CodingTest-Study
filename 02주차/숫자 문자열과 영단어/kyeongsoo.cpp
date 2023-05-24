#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(string s) {
    string answer = "";
    map<string, char> numbers = 
    {
        {"zero", '0'},
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'},
    };
    
    string tmp = "";
    for(char t : s){
        if(isdigit(t)){ answer += t; continue; }
        tmp += t;
        if(numbers.find(tmp) != numbers.end()){
            answer += numbers[tmp];
            tmp = "";
        }
    }
    return stoi(answer);
}
