#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    int trash = score.size() % m;
    int i = trash;
    while (i < score.size())
    {
        answer += *min_element(score.begin() + i, score.begin() + i + m) * m;
        i += m;
    }
    return answer;
}
