#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //종류별 개수 저장
    map<string, int> clothMap;
    //두 번째 원소가 해당 의상 종류
    for(vector<string> cloth : clothes){
        clothMap[cloth[1]] += 1;
    }
    //안입거나, 다른 걸 입거나 이므로 +1하여 곱한다.
    for(auto itr : clothMap)
        answer *= itr.second+1;
    //아예 안입으면 안됨
    return answer-1;
}
