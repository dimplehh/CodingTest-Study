#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    vector<int> v_ints;
    int max, min;
    if (a > b) {max = a; min = b;}
    else if (a < b) {max = b; min = a;} 
    
    for (min ; min <= max; min++){
        answer += min;
    }
    
    return answer;
}
