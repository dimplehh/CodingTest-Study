#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> answer;
vector<vector<string>> temp;
vector<vector<string>> qTemp;
void putInfo(vector<string> info)
{
    for(int i = 0; i < info.size(); i++)
    {
        vector<string> oneInfo;
        int index = 0;
        for(int j = 0; j < 5; j ++)
        {
            index = info[i].find(' ');
            oneInfo.push_back(info[i].substr(0, index));
            info[i] = info[i].substr(info[i].find(' ') + 1);
        }
        temp.push_back(oneInfo);
    }//temp라는 2차원 벡터에 info 초기화
}

void putQuery(vector<string> query)
{
    for(int i = 0; i < query.size(); i++)
    {
        vector<string> oneQuery;
        int index = 0;
        for(int j = 0; j < 3; j ++)
        {
            index = query[i].find(" and ");
            oneQuery.push_back(query[i].substr(0, index));
            query[i] = query[i].substr(query[i].find(" and ") + 5);
        }
        index = query[i].find(' ');
        oneQuery.push_back(query[i].substr(0, index));
        oneQuery.push_back(query[i].substr(index + 1));
        qTemp.push_back(oneQuery);
    }//qTemp라는 2차원 벡터에 query 초기화
}

void setAnswer(vector<string> info, vector<string> query)
{
    for(int i = 0; i < query.size(); i++)
    {
        //처음부터 map으로 구현했어야 한다...
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    putInfo(info);
    putQuery(query);
    setAnswer(info, query);
    return answer;
}

    // for(int i = 0; i < temp.size() ; i++)
    // {
    //     for(int j = 0; j < temp[i].size(); j++)
    //     {
    //         cout << temp[i][j] << ",";
    //     }
    //     cout << endl;
    // }
