#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int weight;
    int count;
    sort(dungeons.begin(), dungeons.end());
    do {
        weight = k;
        count = 0;
        for (vector<int> d : dungeons) {
                if (weight >= d[0]) {
                    weight -= d[1];
                    count++;
                }
        }
        answer = max(count, answer);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}
