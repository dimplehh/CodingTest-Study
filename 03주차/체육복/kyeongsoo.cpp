#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> SetDifference(vector<int> vec1, vector<int> vec2) {
    vector<int> result(vec1.size()+ vec2.size());
    auto itr = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());
    result.erase(itr, result.end());

    return result;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> lostCheck = SetDifference(lost, reserve);
    vector<int> recvCheck = SetDifference(reserve, lost);
    
    sort(lostCheck.rbegin(), lostCheck.rend());
    sort(recvCheck.rbegin(), recvCheck.rend());

    
    answer = n - lostCheck.size();


    
    while (!lostCheck.empty()) {
        while (!recvCheck.empty() && recvCheck.back() < lostCheck.back() - 1) 
            recvCheck.pop_back();
        if (recvCheck.empty()){
            break;
        }

        if (abs(lostCheck.back() - recvCheck.back()) == 1) {
            answer++;
            recvCheck.pop_back();
        }
        cout << lostCheck.back() << endl;
        lostCheck.pop_back();
    }
    return answer;
}
