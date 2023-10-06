#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int len;
int answer = 0;

set<int> ponketmon;

int solution(vector<int> nums)
{
    
    for(auto p : nums)
    {
        ponketmon.insert(p);
    }
    
    if(ponketmon.size() > nums.size() / 2)
        answer = nums.size() / 2;
    else
        answer = ponketmon.size();
    return answer;
}
