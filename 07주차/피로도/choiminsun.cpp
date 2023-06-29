#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> visit;

int count(vector<bool> v)
{
    int c = 0;

    for (bool b : v)
    {
        if (b == true)
            c++;
    }

    return c;
}

int search(int k, vector<vector<int>> dungeons)
{
    int answer = 0;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visit[i] == false && k >= dungeons[i][0]) //방문 가능
        {
            visit[i] = true;
            answer = max(answer, search(k - dungeons[i][1], dungeons)); //이전 방문과 이번 방문 비교
            visit[i] = false; //다음 경우를 위해 방문 취소
        }

        if (answer == dungeons.size())
            return answer;
    }

    return max(answer, count(visit)); //이번 층에서 가장 큰 방문 수
}

int solution(int k, vector<vector<int>> dungeons)
{
    visit.resize(dungeons.size(), false);

    return search(k, dungeons);
}