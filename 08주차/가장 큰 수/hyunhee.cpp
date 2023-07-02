#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
    if(stoll(a + b) > stoll(b + a))
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(int i = 0; i < numbers.size(); i++)
        temp.push_back(to_string(numbers[i]));
    sort(temp.begin(), temp.end(), cmp); //cmp : true시 앞 뒤 값을 바꾸겠다.
    for(string str:temp) //temp배열에서 string 요소 하나씩 참조해서 들어가겠다.
        answer += str;
    if(answer[0] == '0')
        return "0";
    return answer;
}
