#include <string>
#include <vector>
#include <iostream>
#define MIN(x,y)(((x)<(y))?(x):(y))
using namespace std;

string solution(string X, string Y) {
    string answer = "";

    // 구성된 숫자들 집합
    int arrX[10] = { 0, };
    int arrY[10] = { 0, };
    int arrXY[10] = { 0, };
    // 만약 X = 111122333, Y = 33444 이면,
    // arrX = [ 0, 4, 2, 3, 0, 0, 0, 0, 0, 0 ]
    // arrY = [ 0, 0, 0, 2, 3, 0, 0, 0, 0, 0 ]
   // arrXY = [ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 ]

    // arrX, arrY 채우기
    for (int i = 0;i < X.size();i++) {
        arrX[X[i] - '0']++;
    }
    for (int i = 0;i < Y.size();i++) {
        arrY[Y[i] - '0']++;
    }

    //arrXY 채우기
    for (int i = 0;i < 10;i++) {
        arrXY[i] = MIN(arrX[i], arrY[i]);
    }

    //큰 숫자 짝꿍 생성
    for (int i = 9;i >= 0;i--) {
        for (int j = 0;j < arrXY[i];j++) {
            if (answer == "0" && i == 0) return answer;
            answer += to_string(i);
        }
    }

    // 만약 answer가 채워지지 않았다면, 만들 수 있는 짝꿍이 없다는 뜻이므로 -1 리턴
    if (answer == "") return "-1";

    return answer;
}