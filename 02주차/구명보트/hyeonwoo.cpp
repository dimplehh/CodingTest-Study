#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int pickedPeople[50000] = { 0, };

bool isPickedAll(int peopleCnt) {
    for (int i = 0; i < peopleCnt; i++) {
        if (pickedPeople[i] == 0) return false;
    }
}

int solution(vector<int> people, int limit) {
    int answer = 0, idx=0, peopleCnt=0, target;
    sort(people.begin(), people.end());

    do {
        target = people.back();
        people.pop_back();
        if (target + people[idx] <= limit) {
            answer++;
            idx++;
        }
        else {
            answer++;
        }
        peopleCnt = people.size();
    } while (peopleCnt > idx);

    return answer;
}