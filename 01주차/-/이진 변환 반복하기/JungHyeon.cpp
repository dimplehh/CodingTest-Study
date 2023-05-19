#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string To_Binary(int num) {
    string result;
    while (num != 0) {
        result += (num % 2 == 0 ? "0" : "1");
        num /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int step=0, zero_cnt=0;
    
    while(s.compare("1") != 0){
        step++;
        zero_cnt += count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        s = To_Binary(s.size());
    }
    answer.push_back(step);
    answer.push_back(zero_cnt);
    
    return answer;
}
