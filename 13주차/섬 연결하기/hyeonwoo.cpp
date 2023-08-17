#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[101]; // ��尡 ��� ����Ǿ����� Ȯ�ο� �迭, ������ �ٲ���� üũ

bool compare(vector<int> a, vector<int> b) { // ���� �������� ����
    return a[2] <= b[2];
}

// �θ��� ��ȣ ��������� Ž���ؼ� ����
int getParent(int node) {
    if (check[node] == node) return node;
    return getParent(check[node]);
}

// �� ��带 ����
void setUnion(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    check[b] = a; // check[a] = b  �ص� ��
}

// ����Ŭ ���� ���� Ȯ��
bool isCycle(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);
    if (x == y) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // ���� �������� ����
    sort(costs.begin(), costs.end(), compare);

    // �� ���� �ڱ��ڽ��� �θ��
    for (int i = 0;i < n;i++)
        check[i] = i;

    // ���� ���� ���� ����ŭ kruskal ����
    for (int i = 0;i < costs.size();i++) {

        // ����Ŭ ��������� ���, �������� �ʴ´�
        if (isCycle(costs[i][0], costs[i][1])) continue;

        // ����Ŭ �ƴ� ��� ����
        answer += costs[i][2]; // ���信 �ش� ���� ����ġ �߰�
        setUnion(costs[i][0], costs[i][1]); // ����

    }

    return answer;
}