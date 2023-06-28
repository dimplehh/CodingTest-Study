#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> multi_set;

//// DFS로 집합 찾기 -> 시간복잡도 때매 탈락
//void findSet(vector<int> temp, int n, int s,int sum, int current) {
//    if (temp.size() == n) {
//        if (sum == s) {
//            multi_set.push_back(temp);
//            for (int i = 0; i < temp.size(); i++) {
//                cout << temp.back();
//                temp.pop_back();
//            }
//            cout << endl;
//            return;
//        }
//        else return;
//    }
//    else {
//        for (int i = 1; i < s; i++) {
//            if (sum <= i) continue;
//            sum += i;
//            temp.push_back(sum);
//            findSet(temp, n, s, sum);
//        }
//    }
//}

vector<int> solution(int n, int s) {
    vector<int> temp;

    if (s < n)
        for (int i = 0; i < n; i++) {
            temp.push_back(s / n);
        }

    int tempSize = s % n;
    int tempInt = 0;
    while (tempSize--) {
        temp[tempInt++ % temp.size()]++;
    }
    sort(temp.begin(), temp.end());
    return temp;
}

int main() {
    solution(2, 9);
}