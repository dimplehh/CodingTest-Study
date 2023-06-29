#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    vector<string> answer(participant.size());
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    auto itr = set_difference(participant.begin(), participant.end(),
                  completion.begin(), completion.end(), answer.begin());
    answer.erase(itr, answer.end());
    return answer[0];
}
