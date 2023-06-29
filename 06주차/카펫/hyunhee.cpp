#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w = 0;
    int h;
    //h = (brown - 4)/2 - w;//2 * w + 2 * h + 4 = brown;
    //h = yellow / w;    //w * h = yellow;
    //yellow / w = (brown - 4) / 2 - w;
    for (int i = 0; i < brown / 2; i++)
    {
        w += 1;
        if((w * ((brown - 4) / 2 - w) - yellow) == 0)
            break;
    }
    if(w < yellow / w)
    {
        int temp;
        temp = w;
        w = yellow / w;
        h = temp; 
    }
    else
        h = yellow / w;
    answer.push_back(w + 2);
    answer.push_back(h + 2);
    return answer;
}
