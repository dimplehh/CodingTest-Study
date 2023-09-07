#include <string>
#include <vector>


using namespace std;

int solution(string word) {
    int answer = 0;
    int weight[5];
    weight[0] = 1;
    string wo = "AEIOU";

    for (int i = 1; i < 5; i++)
        weight[i] = weight[i - 1] * 5 + 1;

    for (int i = 0; i < word.length(); i++) {
        answer += weight[4 - i] * wo.find(word[i]) + 1;
    }

    return answer;
}