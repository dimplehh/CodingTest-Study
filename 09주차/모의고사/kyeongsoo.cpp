#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int pattern1[] = {1,2,3,4,5};
    int pattern2[] = {2,1,2,3,2,4,2,5};
    int pattern3[] = {3,3,1,1,2,2,4,4,5,5};
    int score[] = {0, 0, 0};

    int size_p1 = sizeof(pattern1) / sizeof(int);
    int size_p2 = sizeof(pattern2) / sizeof(int);
    int size_p3 = sizeof(pattern3) / sizeof(int);
    for(int i = 0; i < answers.size(); i++){
        if (answers[i] == pattern1[i%size_p1])
            score[0] += 1;
        if (answers[i] == pattern2[i%size_p2])
            score[1] += 1;
        if (answers[i] == pattern3[i%size_p3])
            score[2] += 1;
    }
        

    int *MAX = max_element(begin(score), end(score));
    for(int i = 0; i < 3; i++){
        if(score[i] == *MAX)
            answer.push_back(i+1);
    }
    
    return answer;
}
