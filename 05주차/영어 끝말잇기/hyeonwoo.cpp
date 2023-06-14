#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;


    int turn = 0;
    char lastChar = NULL;
    char firstChar;

    // 해시에 담기는 구조 - <말한 문자열 , n번째 사람>
    unordered_map<string, int> h;

    for (int i = 0; i < words.size(); i++) {

        turn = 1 + i / n;
        firstChar = words[i][0];

        if (lastChar != NULL && lastChar != firstChar) { // 마지막 단어랑 일치하지 않는 경우 컷
            answer.push_back((i % n) + 1);
            answer.push_back(turn);
            return answer;
        }
        if (h.find(words[i]) != h.end()) { // 중복된 단어 말하면 컷
            answer.push_back((i % n) + 1);
            answer.push_back(turn);
            return answer;
        }
        else { // 해시맵에 등록
            h.insert(make_pair(words[i], i));
            lastChar = words[i][words[i].size() - 1]; // 마지막에 부른 단어 갱신
        }
    }

    // 정상적으로 끝말잇기 끝난경우
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}