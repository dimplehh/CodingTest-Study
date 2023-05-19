#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> num; // = new vector<long long>;

    for (; n >= 10; n /= 10) //숫자 분해해서 list에 넣기
    {
        num.push_back(n % 10);
    }
    num.push_back(n);


    sort(num.begin(), num.end()); //정렬


    for (int i = num.size() - 1; i >= 0; i--) //다시 정수로 반환
    {
        answer = answer * 10 + num[i];
    }

    return answer;
}