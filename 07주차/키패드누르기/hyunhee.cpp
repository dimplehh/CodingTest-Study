#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<string> ans;
    vector<pair<int, int>> v[10];
    pair<int, int> l = {0, 3};
    pair<int, int> r = {2, 3};
    v[0].push_back({1,3});
    for (int i = 1; i <= 9; i++)
        v[i].push_back({(i + 2) % 3, (i - 1) / 3}); //배열 위치 초기화
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] % 3 == 1)
            answer.push_back('L');
        else if(numbers[i] % 3 == 0 && numbers[i] != 0)
            answer.push_back('R');
        else
        {
            if(abs(v[numbers[i]][0].first - l.first)+abs(v[numbers[i]][0].second - l.second)>abs(v[numbers[i]][0].first - r.first)+abs(v[numbers[i]][0].second - r.second))
                answer.push_back('R');
            else if(abs(v[numbers[i]][0].first - l.first)+abs(v[numbers[i]][0].second - l.second)<abs(v[numbers[i]][0].first - r.first)+abs(v[numbers[i]][0].second - r.second))
                answer.push_back('L');
            else if(abs(v[numbers[i]][0].first - l.first)+abs(v[numbers[i]][0].second - l.second)==abs(v[numbers[i]][0].first - r.first)+abs(v[numbers[i]][0].second - r.second))
            {
                if (hand == "right")
                    answer.push_back('R');
                else if(hand == "left")
                    answer.push_back('L');
            }
        }
        if(answer.back() == 'L')
            l = v[numbers[i]][0];
        else if(answer.back() == 'R')
            r = v[numbers[i]][0];
    }
    return answer;
}
