#include <string>
#include <vector>

using namespace std;

int arr[100000];

int solution(int number, int limit, int power) {

    int answer = 0;

    // 약수의 합 가진 배열 number 크기만큼 초기화
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3;i <= number;i++) {
        arr[i] = 2;
        for (int j = 2;j <= i / 2;j++) {
            if (i % j == 0) arr[i]++;
        }
    }

    // 약수의 합 가진 배열에서 limit보다 큰 얘 검사
    for (int i = 1;i <= number;i++) {
        if (arr[i] > limit) answer += power; // 만약 limit보다 크면 answer에 power 를 더함
        else answer += arr[i]; // 그외의 경우(limit 보다 작거나 같으면) 그냥 약수의 총합 더함
    }

    return answer;
}