#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 0 1 1 0 1 1 1 0 0 1 0 1 1 1 0 1 1 1 ...
// 0 1 2 3 4 5 6 7 8 9 1 0 1 1 1 2 1 3 1 4 1 5 1 6 1 7 ...

string ref_string = "0123456789ABCDEF";
string ref_answer = "";


// num을 n진수로 변환
string temp = "";
string convert(int n, int num) {
    if (num / n == 0) return temp + ref_string[num % n];
    else return convert(n, num / n) + ref_string[num % n];
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    ref_answer = "";

    // 미리 정답을 만들어 놓는다
    for (int i = 0;i <= m * t + p;i++) {
        ref_answer += convert(n, i);
    }

    //cout << ref_answer;

    int idx = 0; // 튜브가 말해야 할 인덱스 번호, ex : 0 2 4 6 8 10 12 ...
    idx += p - 1; // 튜브가 말할 숫자 순서

    // 튜브가 말해야 하는 수만큼 반복
    for (int i = 0;i < t;i++) {

        //cout << ref_answer[idx] << ' ';
        answer += ref_answer[idx];
        idx += m;

    }

    return answer;
}

int main() {
    solution(2, 4, 2, 1);
    cout << '\n';
    solution(16, 16, 2, 1);
    cout << '\n';
    solution(16, 16, 2, 2);
    cout << '\n';
}