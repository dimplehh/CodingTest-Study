#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> array2;
    for(int i =0;i < commands.size(); i++)
    {
//         for(int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++)
//             array2.push_back(array[j]);
//         sort(array2.begin(), array2.end());
//         answer.push_back(array2[commands[i][2] - 1]);
//         array2.clear();
        array2 = array;
        sort(array2.begin() + commands[i][0] - 1, array2.begin() + commands[i][1]);
        answer.push_back(array2[commands[i][0] + commands[i][2]-2]);
    }
    return answer;
}
