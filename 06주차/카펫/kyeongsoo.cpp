#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    //w*h = brown+yellow
    //y.w*y.h = y; y.w = w-2; y.h =  h-2;
    //(w-2)(h-2) = yellow;
    //w*h(== brown+yellow) -2(w+h) + 4 = yellow;
    //2(w+h) = 4 + brown;
    //w+h = (4+brown)/2;
    int tileNum = brown + yellow;
    int sumWH = (4+brown)/2;
    int i = 0;
    for(i=3; i<=sumWH/2; i++){
        if((i-2)*(sumWH-i-2) == yellow)
            break;
    }
    return {sumWH-i, i}; // {w, h}
}
