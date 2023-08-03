#include <iostream>
#define FUNC_Z(a,b)(((b)*100)/(a))
using namespace std;

long long X, Y, Z;
int cnt = 0;

// cnt 기록 -> 시간초과
// 
//int main() {
//    cin >> X >> Y;
//    Z = (Y * 100 / X);
//    int temp = Z;
//
//    if (Z >= 99) {
//        cnt = -1;
//    }
//    else {
//        while (temp != Z + 1) {
//            X++; Y++; cnt++;
//
//            temp = (Y * 100) / X;
//        }
//    }
//
//    cout << cnt;
//}

int main() {
	long long X, Y, Z, temp_Z, left, right, mid, answer;
	cin >> X >> Y;

	// Z값 구하기
	Z = temp_Z = FUNC_Z(X, Y);
	if (Z >= 99) { cout << -1; return 0; } // 이때 승률이 99 넘는 경우, 아무리 이겨도 승률 변하지 않으므로 -1 출력

	// 이분탐색 
	left = 1; right = 1000000000;
	while (left <= right) {
		mid = (left + right) / 2;
		temp_Z = FUNC_Z(X + mid, Y + mid);
		//cout << "["<< X + mid<<","<<Y + mid <<","<<Z <<"," << temp_Z << "]" << '\n';
		if (Z < temp_Z) right = mid - 1, answer = mid;
		else left = mid + 1;
	}

	cout << answer;
	return 0;
}