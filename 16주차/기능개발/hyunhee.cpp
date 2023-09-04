#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> st;
    int max = 0;
    int temp;
    for(int i = 0; i < progresses.size(); i++)
    {
        temp = (100 - progresses[i]) / speeds[i];
        if(!((100 - progresses[i]) % speeds[i] == 0)) temp += 1;
        if(i == 0) max = temp;
        else
        {
            if(temp > max)
            {
                max = temp;
                answer.push_back(st.size());
                while(!st.empty()) st.pop();
            }
        }
        st.push(temp);
    }
    answer.push_back(st.size());
    return answer;
}
