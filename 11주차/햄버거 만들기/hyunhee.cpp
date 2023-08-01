#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> temp;
    int stat = 1;
    for(int i = 0; i < ingredient.size(); i++)
    {
        if(ingredient[i] == 1)
        {
            if(temp.size() >= 3)
            {
                int three = temp.top();
                temp.pop();
                int two = temp.top();
                temp.pop();
                int one = temp.top();
                if(one == 1 && two == 2 && three == 3)
                {
                    temp.pop();
                    answer++;
                }
                else
                {
                    temp.push(two);
                    temp.push(three);
                    temp.push(ingredient[i]);
                }
            }
            else
                temp.push(ingredient[i]);
        }
        else
            temp.push(ingredient[i]);
    }
    return answer;
}
