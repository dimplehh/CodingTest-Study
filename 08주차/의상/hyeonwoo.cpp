#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 옷 종류 , 종류별 count 담는 해시 선언
    unordered_map<string, int> clothes_map;

    // 옷 해시에 담기
    for (int i = 0;i < clothes.size();i++) clothes_map[clothes[i][1]]++;

    for (auto i = clothes_map.begin(); i != clothes_map.end(); i++) {
        // 모든 경우의 수 구해서 정답에 담기
        answer = answer * (i->second + 1);
    }

    // 안입는경우 제외 (-1)
    return answer - 1;
}