#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

bool comp(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numList;

    // int list -> string list
    for (int i = 0;i < numbers.size();i++)
        numList.push_back(to_string(numbers[i]));

    // 정렬
    sort(numList.begin(), numList.end(), comp);

    // 처음부터 0이면 바로 0 리턴
    if (numList[0] == "0") return "0";

    // 정답에 정렬된거 다 담기
    for (int i = 0;i < numList.size();i++)
        answer += numList[i];

    return answer;
}