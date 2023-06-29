#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

void SetDP(vector<int>& dp, queue<int>& myQueue, int num, int &n) {
    if (dp.size() > num + n && (dp[num+n]== 0 || dp[num + n] > dp[num]+1))
    { dp[num + n] = dp[num] + 1; myQueue.push(num + n); cout << myQueue.back() << " "; }
    if (dp.size() > num * 2 && (dp[num * 2] == 0 || dp[num * 2] > dp[num] + 1))
    { dp[num * 2] = dp[num] + 1; myQueue.push(num * 2); cout << myQueue.back() << " "; }
    if (dp.size() > num * 3 && (dp[num * 3] == 0 || dp[num * 3] > dp[num] + 1))
    { dp[num * 3] = dp[num] + 1; myQueue.push(num * 3); cout << myQueue.back() << " "; }
    cout << endl;
}

int solution(int x, int y, int n) {
    vector<int> dp(y + 1, 0);
    queue<int> myQueue;
    myQueue.push(x);
    while (!myQueue.empty()) {
        int tmp = myQueue.front();
        myQueue.pop();
        SetDP(dp, myQueue, tmp, n);
        if (dp[y])
            break;
    }
    return dp[y] ? dp[y] : -1;
}

//==============다른 풀이법================

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

const int INT_MAX = 2147483647;

using namespace std;

void SetDP(vector<int>& dp, queue<int>& myQueue, int num, int &n) {
    if (dp.size() > num + n && dp[num + n] > dp[num]+1)
    { dp[num + n] = dp[num] + 1; myQueue.push(num + n); }
    if (dp.size() > num * 2 && dp[num * 2] > dp[num] + 1)
    { dp[num * 2] = dp[num] + 1; myQueue.push(num * 2); }
    if (dp.size() > num * 3 && dp[num * 3] > dp[num] + 1)
    { dp[num * 3] = dp[num] + 1; myQueue.push(num * 3); }
}

int solution(int x, int y, int n) {
    if(x > y)
        return -1;
    else if(x == y)
        return 0;
    vector<int> dp(y + 1, INT_MAX);
    dp[x] = 0;
    queue<int> myQueue;
    myQueue.push(x);
    
    while (!myQueue.empty()) {
        int tmp = myQueue.front();
        myQueue.pop();
        SetDP(dp, myQueue, tmp, n);
        if (dp[y] != INT_MAX)
            break;
    }
    return dp[y] != INT_MAX ? dp[y] : -1;
}
