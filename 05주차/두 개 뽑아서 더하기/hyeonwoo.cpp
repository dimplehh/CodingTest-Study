#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    sort(numbers.begin(), numbers.end());

    answer.push_back(numbers[0] + numbers[1]);
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    // unique 함수 : 중복 원소를 마지막값(쓰레기값)으로 변환 후 뒤로 보냄
    // 예시 : 1,2,2,3,3,4,4 → 1,2,3,4,4,4,4
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}