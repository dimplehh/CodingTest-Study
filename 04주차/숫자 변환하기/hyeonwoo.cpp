
#include <string>
#include <vector>
#include <queue>

using namespace std;

//// 실패 - 실행시간 초과
//int res=1000001;
//void DFS_Find(int x, int y, int n, int cnt=0) {
//    if (x > y) return;
//    if (x == y) {
//        if (res > cnt) res = cnt;
//        return;
//    }
//    DFS_Find(x + n, y, n, cnt + 1);
//    DFS_Find(x * 2, y, n, cnt + 1);
//    DFS_Find(x * 3, y, n, cnt + 1);
//}

int solution(int x, int y, int n) {
    // 실패 - 실행시간 초과
    //DFS_Find(x, y, n);
    //if (res == 1000001) return -1;
    //return res;

    // BFS 탐색
    bool vis[1000001] = { 0, };

    if (x == y) return 0;

    queue<pair<int, int>> q;
    int cnt = 0, item = 0;
    q.push(make_pair(x, cnt));

    while (!q.empty()) {
        item = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (item + n <= y && !vis[item + n]) {
            if (item + n == y) return cnt + 1;
            vis[item + n] = true;
            q.push(make_pair(item + n, cnt + 1));
        }
        if (item * 2 <= y && !vis[item * 2]) {
            if (item * 2 == y) return cnt + 1;
            vis[item * 2] = true;
            q.push(make_pair(item * 2, cnt + 1));
        }
        if (item * 3 <= y && !vis[item * 3]) {
            if (item * 3 == y) return cnt + 1;
            vis[item * 3] = true;
            q.push(make_pair(item * 3, cnt + 1));
        }
    }

    return -1;
}