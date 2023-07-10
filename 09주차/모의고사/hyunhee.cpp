#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> mmax(int ans[3])//int형 배열을 매개변수로
{
    vector<int> answer;
    int maxx = max(ans[0], ans[1]);
    maxx = max(maxx, ans[2]);
    for(int i = 0; i < 3; i++)
    {
        if(ans[i] == maxx)
            answer.push_back(i + 1);
    }
    return answer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans[3] = {0, };
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10]={3,3,1,1,2,2,4,4,5,5};
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == one[i % 5])
            ans[0]++;
        if(answers[i] == two[i % 8])
            ans[1]++;
        if(answers[i] == three[i % 10])
            ans[2]++;
    }
    return mmax(ans);
}
