#include <iostream>

using namespace std;

int a[100] = { 0, };
int temp[100] = { 0, };

void divide(int lt, int rt) {
	if (lt < rt) {
		int mid, p1, p2, p3;
		mid = (lt + rt) / 2;
		divide(lt, mid);
		divide(mid + 1, rt);
		p1 = lt;
		p2 = mid + 1;
		p3 = lt;
		while (p1 <= mid && p2 <= rt) {
			if (a[p1] > a[p2]) temp[p3++] = a[p2++];
			else temp[p3++] = a[p1++];
		}
		while (p1 <= mid) temp[p3++] = a[p1++];		// 한쪽이 먼저 끝나서, 남아있는 경우 
		while (p2 <= rt) temp[p3++] = a[p2++];
		for (int i = lt; i <= rt; i++) {		// a배열을 재배치 
			a[i] = temp[i];
		}

	}
}

long long solution(long long n) {
	long long answer = 0;
	int idx = 0;

	while (n > 0) {
		int tmp = n % 10;
		a[idx++] = tmp;
		n /= 10;
	}

	divide(0, idx - 1);
	while (idx--) {
		answer += a[idx];
		if (idx != 0) answer *= 10;
	}
	return answer;
}