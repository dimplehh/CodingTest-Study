#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<bool> isUsed(10000000000, false);
bool canReturn = false;
void DFS(int depth, vector<vector<string>> &tickets, vector<string> &answer, string start)
{
    if(depth == tickets.size())
        canReturn = true;
    answer.push_back(start);
    for(int i = 0; i < tickets.size(); i++)
    {
        if(tickets[i][0] == start && !isUsed[i])
        {
            isUsed[i] = true;
            DFS(depth + 1, tickets, answer, tickets[i][1]);
            if(!canReturn)
            {
                answer.pop_back();
                isUsed[i] = false; //DFS뒤에 backTracking
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    DFS(0, tickets, answer, "ICN");
    return answer;
}
