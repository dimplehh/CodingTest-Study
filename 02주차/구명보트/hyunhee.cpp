#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int result = 0;
    sort(people.begin(), people.end());
    int i = 0;
    while(i< people.size())
    {
        if(people[i] + people.back() <= limit)
            i++;
        result++;
        people.pop_back();
    }
    return result;
}
