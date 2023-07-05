#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    int arr[10][2] = {0,};
    //각 수를 이루는 숫자들의 개수 저장 
    for(char n : X){
        arr[ n - '0'][0] += 1;
    }
        for(char n : Y){
        arr[ n - '0'][1] += 1;
    }
    //가장 큰 정수를 만들어야 하므로 가장 큰 값부터 반복문 시작
    string answer = "";
    for(int i = 9; i >= 0; i--){
        //두 수 중 더 적게 갖는 값이 해당 숫자를 공통으로 갖는 개수
        for(int j = 0; j < min(arr[i][0], arr[i][1]); j++){
            answer += to_string(i);
        }
    }
    //공통된 숫자가 없음
    if(answer.length() <=0)
        return "-1";
    //공통된 숫자가 0뿐임
    else if(answer[0] == '0')
        return "0";
    else
        return answer;
}
