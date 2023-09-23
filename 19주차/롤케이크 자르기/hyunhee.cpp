#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int obCnt = 0;
    unordered_map<int, int> obMap, ybMap; //각자 map을 만든다.
    
    for(auto topp : topping) obMap[topp]++; //topping전체 map을 setting한다.
    obCnt = obMap.size();//처음 세팅한 맵의 크기를 형의 토핑개수로 정한다.
    
    for (auto topp: topping)//for문을 처음부터 돌리며 동생의 토핑값을 늘려간다.
    {
        ybMap[topp]++;
        obMap[topp]--; //동생의 토핑map은 늘리고 형의 토핑map은 줄여
        if(obMap[topp] == 0) obCnt--; //형 map이 0이 될 경우 카운트를 줄임
        if(ybMap.size() == obCnt) answer++;
    }
    
    return answer;
}
