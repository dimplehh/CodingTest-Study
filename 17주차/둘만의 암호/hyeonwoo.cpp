#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ref_s = "abcdefghijklmnopqrstuvwxyz";

string solution(string s, string skip, int index) {
    string answer = "";

    for (int i = 0;i < skip.size();i++) {
        char target = skip[i];
        ref_s.erase(ref_s.begin() + ref_s.find(target));
    }

    for (int i = 0;i < s.size();i++) {
        int idx = (ref_s.find(s[i]) + index) % ref_s.size();
        answer += ref_s[idx];
    }
    return answer;
}