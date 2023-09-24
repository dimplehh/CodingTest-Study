#include <string>
#include <vector>
#include <iostream>

#define MIN(a,b)(((a)<(b))?(a):(b))
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = 999, minY = 999, maxX = -1, maxY = -1;

    for (int i = 0;i < wallpaper.size();i++) {
        for (int j = 0;j < wallpaper[i].size();j++) {
            if (wallpaper[i][j] == '#') {
                minX = MIN(minX, i);
                minY = MIN(minY, j);
                maxX = MAX(maxX, i);
                maxY = MAX(maxY, j);
            }
        }
    }

    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX + 1);
    answer.push_back(maxY + 1);

    return answer;
}