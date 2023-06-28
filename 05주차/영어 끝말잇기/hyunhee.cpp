#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> map;
    int result[2] = {0, 1};
    bool end = false;
    for (int i = 0; i < words.size();i++)
    {
        char alp;
        result[0] += 1;
        if(result[0] > n)
        {
            result[0] =  1;
            result[1] += 1;
        }
        if((map.find(words[i]) != map.end()) || (alp && words[i].at(0) != alp))
        {
            end = true;
            break;   
        }
        else
        {
            map[words[i]] = 1;
            alp = words[i].at(words[i].size() - 1);
        }
    }
    if(end)
    {
        answer.push_back(result[0]);
        answer.push_back(result[1]);   
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
