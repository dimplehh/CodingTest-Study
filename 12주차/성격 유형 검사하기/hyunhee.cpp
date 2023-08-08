#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
void init(unordered_map<char, int> &mbti)
{
    mbti.insert({'R', 0}); mbti.insert({'T', 0});
    mbti.insert({'C', 0}); mbti.insert({'F', 0});
    mbti.insert({'M', 0}); mbti.insert({'J', 0});
    mbti.insert({'A', 0}); mbti.insert({'N', 0});
}

void insert(unordered_map<char, int> &mbti, vector<string> survey, vector<int> choices)
{
    for(int i = 0; i < survey.size(); i++)
    {
        if(choices[i] < 4)
            mbti[survey[i][0]] += 4 - choices[i];
        else if (choices[i] > 4)
            mbti[survey[i][1]] += choices[i] - 4;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    string cmp = "TFMN";
    unordered_map<char, int> mbti;
    init(mbti);
    insert(mbti, survey, choices);
    for(int i = 0; i < 4 ; i++)
    {
        if(mbti[answer[i]] < mbti[cmp[i]])
                answer[i] = cmp[i];
    }
    return answer;
}
