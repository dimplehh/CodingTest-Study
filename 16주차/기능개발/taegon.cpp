#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    int cnt = 0;

    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i] == 0)
            day.push_back((100 - progresses[i]) / speeds[i]);
        else
            day.push_back((100 - progresses[i]) / speeds[i] + 1);
    }
    while (!day.empty()) {
        cnt = 0;
        while (1) {
            if (day.size() < cnt + 1) {
                break;
            }
            else if (*day.begin() >= *(day.begin() + cnt)) {
                cnt++;
            }
            else {
                break;
            }
        }

        day.erase(day.begin(), day.begin() + cnt);
        answer.push_back(cnt);
    }
    return answer;
}