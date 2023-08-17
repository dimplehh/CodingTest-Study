#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[101]; // 노드가 어디에 연결되었는지 확인용 배열, 연결노드 바뀌는지 체크

bool compare(vector<int> a, vector<int> b) { // 간선 오름차순 정렬
    return a[2] <= b[2];
}

// 부모노드 번호 재귀적으로 탐색해서 리턴
int getParent(int node) {
    if (check[node] == node) return node;
    return getParent(check[node]);
}

// 두 노드를 연결
void setUnion(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    check[b] = a; // check[a] = b  해도 됨
}

// 사이클 존재 여부 확인
bool isCycle(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);
    if (x == y) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 간선 오름차순 정렬
    sort(costs.begin(), costs.end(), compare);

    // 각 노드는 자기자신을 부모로
    for (int i = 0;i < n;i++)
        check[i] = i;

    // 들어온 간선 정보 수만큼 kruskal ㄱㄱ
    for (int i = 0;i < costs.size();i++) {

        // 사이클 만들어지는 경우, 연결하지 않는다
        if (isCycle(costs[i][0], costs[i][1])) continue;

        // 사이클 아닌 경우 연결
        answer += costs[i][2]; // 정답에 해당 간선 가중치 추가
        setUnion(costs[i][0], costs[i][1]); // 연결

    }

    return answer;
}