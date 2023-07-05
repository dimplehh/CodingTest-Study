#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//비교 함수 - a가 앞에 있는 경우가 더 크면 a를, b가 앞에 있는 경우가 더 크면 b를 먼저 정렬
bool comp(string a, string b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    //정수를 문자열로 변환하여 저장
    vector<string> vec;
    for(auto i : numbers){
        vec.push_back(to_string(i));
    }
    //9, 975, 976, 9999, 8 ... 같이 정렬하여야 함
    sort(vec.begin(), vec.end(), comp);
    //가장 큰 수가 0 == 수가 0밖에 없음
    if(vec[0][0] == '0')
        return "0";
    //정렬한 순서대로 문자열 연결
    for(string s : vec){
        answer += s;
    }
    return answer;
}
