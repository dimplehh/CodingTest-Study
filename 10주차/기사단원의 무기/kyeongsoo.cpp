#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getCount(int r){
    int count = 0;
    int index;
    for(index = 1; index*index < r; index++){
        if(r % index == 0)
            count += 2;
    }
    if(index*index == r)
        count += 1;
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++){
        int cnt = getCount(i);
        
        answer += cnt > limit ? power : cnt;
    }
    return answer;
}
