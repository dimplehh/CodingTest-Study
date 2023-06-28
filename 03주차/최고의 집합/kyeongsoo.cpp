#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int bestNum = ceil((double)s / n);
    cout << bestNum << endl;
    if (s / n <= 0)
        return { -1 };
    int result = (bestNum * n) - s;
    answer.insert(answer.end(), result, bestNum-1);
    answer.insert(answer.end(), n - result, bestNum);
    return answer;
}
