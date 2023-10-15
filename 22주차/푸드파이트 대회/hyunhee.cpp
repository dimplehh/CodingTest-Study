#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<int> st;
    for(int i = 1; i < food.size(); i++)
    {
        int temp = food[i] / 2;
        if(temp > 0)
        {
            for (int j = 0; j < temp; j++)
            {
                answer += to_string(i);
                st.push(i);
            }
        }
    }
    answer += '0';
    while(!st.empty())
    {
        answer += to_string(st.top());
        st.pop();
    }
    return answer;
}
