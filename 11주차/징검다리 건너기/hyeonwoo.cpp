#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ����Ž������ �غôµ� �ð��ʰ� �߻�

// �޸� :
// *max_element(arr.begin(), arr.end())  ->  �迭�� �ִ� ����
// *min_element(arr.begin(), arr.end())  ->  �迭�� �ּڰ� ����


bool IsPossible(int mid, vector<int> stones, int k) {
    int cnt = 0;
    for (int i = 0;i < stones.size();i++) {
        if (stones[i] - mid <= 0) cnt++;
        else cnt = 0;
        if (cnt >= k) return false;
    }
    return true;
}


int solution(vector<int> stones, int k) {
    int start = 1; // �ٸ� �ǳ� �� �ִ� �ּ� �ο� = 1
    int end = *max_element(stones.begin(), stones.end()); // �ִ�� �ǳ� �� �ִ� ��� �� = �迭 �ִ밪

    while (start <= end) {
        int answer = 0;
        int mid = (start + end) / 2;
        if (!IsPossible(mid, stones, k)) end = mid - 1;// �� �ǳʴ� ���
        else start = mid + 1;
    }
    return start;
}