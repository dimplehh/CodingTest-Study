#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    vector<int> num;
    int len;
    //num vector에 각 자리 저장
    while (storey) {
        int k = storey % 10;
        num.push_back(k);
        storey /= 10;
    }
    len = num.size();

    for (int i = 0; i < len; i++) {
        //5보다 클때
        if (num[i] > 5) {
            if (i == len - 1) { //가장 끝일 경우
                num.push_back(1);
            }
            else {
                num[i + 1]++;
            }
            answer += 10 - num[i];
        }
        else if (num[i] < 5) { //5보다 작을 때
            answer += num[i];
        }
        else { //5일때
            answer += num[i];
            if (i != len - 1 && num[i + 1] >= 5) {
                num[i + 1]++;
            }
        }
    }
    if (num[len - 1] > 5) {
        answer++;
    }

    return answer;
}