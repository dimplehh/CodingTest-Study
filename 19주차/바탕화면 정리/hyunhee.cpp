#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = 50, luy = 50, rdx = 0, rdy = 0;
    for(int j = 0; j < wallpaper.size(); j++)
    {
        for(int i = 0; i < wallpaper[j].size(); i++)
        {
            if(wallpaper[j][i] == '#')
            {
                if(luy > i) luy = i;
                if(rdy <= i) rdy = i + 1;
            }
        }
        if(wallpaper[j].find('#') != string::npos)
        {
            if(lux > j) lux = j;
            if(rdx <= j) rdx = j + 1;
        }
    }
    answer = {lux, luy, rdx, rdy};
    return answer;
}
