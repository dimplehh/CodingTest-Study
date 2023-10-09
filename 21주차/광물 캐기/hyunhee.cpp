#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
priority_queue<pair<int, int>>pq;
vector<int> new_picks;
int new_minerals[50];
int answer = 0;
string name[3] = {"diamond", "iron", "stone"};
int temp[3] = {25, 5, 1};
void make_pq(vector<string> minerals)
{
    int hap = 0, idx = 0;
    for(int i = 0; i < minerals.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(minerals[i] == name[j])
            {
                new_minerals[i] = temp[j];
                hap += temp[j];
                break;
            }
        }
        if((i + 1) % 5 == 0 || i == minerals.size() - 1)
        {
            pq.push(make_pair(hap, i / 5));
            hap = 0;
        }
    }
}

void make_new_picks(vector<int> &picks)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < picks[i]; j++)
            new_picks.push_back(temp[i]);
}

void set_answer(vector<string> &minerals)
{
    int idx = 0;
    if(pq.top().second * 5 + 5 >= (minerals.size() / 5) * 5)
        if(new_picks.size() * 5 < minerals.size())
            pq.pop();
    while(!pq.empty())
    {
        if(idx >= new_picks.size())
            break;
        int max_i = pq.top().second * 5 + 5;
        if(max_i >= minerals.size()) max_i = minerals.size();
        for(int i = pq.top().second * 5 ; i < max_i; i++)
        {
            int num = new_minerals[i] / new_picks[idx];
            if(num == 0) num = 1;
            answer+= num;
        }
        pq.pop();
        idx++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    make_new_picks(picks); //새로운 곡괭이 배열 만들기 (25,5,5,5,1,1)
    make_pq(minerals); //우선순위 큐 만들기(first: 25,5,1 / second * 5 :인덱스시작위치)
    set_answer(minerals);
    return answer;
}
