#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>


using namespace std;

vector<string> uid, bid;
set<vector<int> > bList;
bool visited[9];

bool IsBanAble(string user, string banned) {
    if (user.size() != banned.size()) return false;
    for (int i = 0;i < banned.size();i++) {
        if (banned[i] == '*') continue;
        if (banned[i] != user[i]) return false;
    }
    return true;
}

void dfs(int idx, vector<int> candidate) {
    if (idx == bid.size()) { // banned_id 에서 후보키 다 찾으면
        // 중복제거, set에 등록
        sort(candidate.begin(), candidate.end());
        bList.insert(candidate);
        return;
    }
    for (int i = 0;i < uid.size();i++) { // banned_id와 user_id 전체를 비교해서 후보키가 될 수 있는지 체크
        if (!visited[i] && IsBanAble(uid[i], bid[idx])) {
            visited[i] = true;
            candidate.push_back(i);
            dfs(idx + 1, candidate);
            visited[i] = false;
            candidate.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    uid = user_id;
    bid = banned_id;
    vector<int> candidate;
    dfs(0, candidate);
    return bList.size();
}

int main() {
    cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" });
}