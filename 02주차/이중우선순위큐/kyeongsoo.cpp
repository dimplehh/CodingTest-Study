
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

//split 기능 함수
vector<string> split(string str, char delimiter);

//벡터의 첫 번째 원소 제거
void pop_front(vector<int> &v){
    if(v.size()>0)
        v.erase(v.begin());
}

//벡터의 마지막 원소 제거
void pop_back(vector<int> &v){
    if(v.size()>0)
        v.pop_back();
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(string s : operations){
        vector<string> cmd = split(s, ' ');
        if(cmd[0].compare("I") == 0){
            answer.push_back(stoi(cmd[1]));
        }
        else{
            sort(answer.rbegin(), answer.rend());
            if(cmd[1].compare("1") == 0){
                pop_front(answer);
            }
            else{
                if(answer.size() > 0)
                pop_back(answer);
            }
        }
    }
    
    //마지막에 제거가 아니라 삽입이 발생했을 경우를 대비해 다시 정렬해야 함
    sort(answer.rbegin(), answer.rend());
    //벡터에 원소가 존재할 경우에만 [최댓값, 최솟값] 출력
    if(answer.size() > 0)
        return {answer.front(), answer.back()};
    else
        return {0,0};
}

//중요!!! 외우기
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
