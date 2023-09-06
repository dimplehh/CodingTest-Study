#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string aeiou[5] = { "A","E","I","O","U" };

using namespace std;

string target;
bool isFound = false;
int cnt = 0;

void dfs(string _word) {
    if (_word.size() > 5) return;
    if (isFound) return;
    if (_word == target) isFound = true;
    //cout << _word << '\n';
    cnt++;
    for (int i = 0;i < 5;i++) dfs(_word + aeiou[i]);
}

int solution(string word) {
    target = word;
    for (int i = 0;i < 5;i++) dfs(aeiou[i]);
    cout << cnt;
    return cnt;
}

int main() {
    solution("I");
}