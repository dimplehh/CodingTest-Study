#include <string>
#include <vector>
#include <string>
#include <map>
#include <iostream>


using namespace std;

int solution(string s) {
    string st;
    string res;
    int answer = 0;
    int temp;

    map<string, string> m;
    m.insert(make_pair("zero", "0"));
    m.insert(make_pair("one", "1"));
    m.insert(make_pair("two", "2"));
    m.insert(make_pair("three", "3"));
    m.insert(make_pair("four", "4"));
    m.insert(make_pair("five", "5"));
    m.insert(make_pair("six", "6"));
    m.insert(make_pair("seven", "7"));
    m.insert(make_pair("eight", "8"));
    m.insert(make_pair("nine", "9"));

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res += s[i];
        }
        else {
            st += s[i];
            if (m.find(st) != m.end() ) {
                res += m.find(st)->second;
                st = "";
            }
        }
    }
    return stoi(res);
}

//int main() {
//    int temp = solution("zero1two");
//    printf("%d", temp);
//}