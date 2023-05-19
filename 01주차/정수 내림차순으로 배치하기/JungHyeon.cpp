#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s_n = to_string(n);
    vector<char> v_chars(s_n.begin(), s_n.end());
    vector<int> v_ints;
    
    for (char c : v_chars){v_ints.push_back((int)(c-'0'));}
    sort(v_ints.begin(), v_ints.end());
    for (int i=0; i<v_ints.size(); i++){answer += v_ints[i]*pow(10,i);}
  
    return answer;
}

    
    /* 다른 풀이
    long long answer = 0;
    string s_n = to_string(n);
    sort(s_n.begin(), s_n.end(), grater<char>());
    answer = atoll(str);
    */
  
