#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {

    int answer = 0;
    int idx = 0;

    // 시간초과
    // 
    //while (idx < ingredient.size() - 3) {
    //    if (ingredient[idx] == 1 && ingredient[idx + 1] == 2 && ingredient[idx + 2] == 3 && ingredient[idx + 3] == 1) {
    //        ingredient.erase(ingredient.begin() + idx, ingredient.begin() + idx + 3);
    //        idx = 0;
    //        answer++;
    //    }
    //    else idx++;
    //}

    vector<int> v = { -1 };
    while (idx < ingredient.size()) {
        if (v.back() == 1 && ingredient[idx] == 2) v.back() = 12;
        else if (v.back() == 12 && ingredient[idx] == 3) v.back() = 123;
        else if (v.back() == 123 && ingredient[idx] == 1) { answer++; v.pop_back(); }
        else v.push_back(ingredient[idx]);
        idx++;
    }

    return answer;
}