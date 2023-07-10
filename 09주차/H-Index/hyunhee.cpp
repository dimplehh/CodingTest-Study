#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end()); //정렬 먼저
    for(int i = 0; i < citations.size(); i++)
    {
        if(citations[i] >= citations.size() - i) // 최초로 그 자리의 숫자가 오른쪽에 위치한 숫자의 개수들보다 크거나 같아질 떄가 정답임
        {
            answer = citations.size() - i;
            break;
        }
    }
    return answer;
}
