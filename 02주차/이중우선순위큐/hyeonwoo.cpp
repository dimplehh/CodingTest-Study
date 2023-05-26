#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> q;
    vector<int> answer;
    int queue_cnt = 0;

    char oper;
    int num;

    for (int i = 0; i < operations.size(); i++) {
        oper = operations[i][0];
        num = stoi(operations[i].erase(0, 2));
        switch (oper) {
        case 'I':
            queue_cnt++;
            q.push_back(num);
            sort(q.begin(), q.end());
            break;
        case 'D':
            if (queue_cnt != 0) {
                queue_cnt--;
                if (num == 1) {
                    q.erase(q.begin() + q.size() - 1);
                }
                else if (num == -1) {
                    q.erase(q.begin());
                }
            }
        }
    }
    if (queue_cnt != 0) {
        answer.push_back(q.back());
        answer.push_back(q.front());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}