#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    //연속되는 구간 중 조건에 만족하는 최소 길이를 구한다 = 투 포인터 기법 사용
    vector<int> answer;
    map<string, int> gemDict;
    int kind;
    for(string g : gems){
        gemDict[g] = 0;
    }
    kind = gemDict.size();
    gemDict.clear();

    //start : 시작구간 end : 마지막 구간
    int start =0;
    int end = 0;
    int minLen = gems.size();
    //start > end일 경우 만족구간을 발견하지 못함
    while(start <= end){
        //start ~ end까지의 보석의 종류가 총 보석의 종류와 같을 때까지
        for(end; end<gems.size(); end++){
            gemDict[gems[end]]++;
            if(kind == gemDict.size()){
                break;
            }
        }
        //end == gems.size() : 만족하는 구간이 존재하지 않음
        if(end == gems.size())
            break;
        //start의 보석을 제외 → 제외 후 0개인 보석 종류가 발생할때까지 → start~end 모든 종류의 보석을 최소 1개 이상 포함하는 가장 짧은 구간
        for(start; start <=end; start++){
            gemDict[gems[start]]--;
            if(gemDict[gems[start]] == 0){
                gemDict.erase(gems[start]);
                break;
            }
        }
        //발견된 가장 짧은 구간과 이전의 구간을 비교
        if(minLen > end-start){
            answer = {start+1, end+1};
            minLen = end-start;
        }
        //다음 구간 검색
        start++; end++;
    }
    
    return answer;
}
