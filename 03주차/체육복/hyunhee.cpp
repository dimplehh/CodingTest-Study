#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n);
    for (int i = 0; i < n; i++)
        students[i] += 1;
    for (int i = 0; i < lost.size(); i++)
        students[lost[i] - 1] -= 1;
    for (int i = 0; i < reserve.size(); i++)
        students[reserve[i] - 1] += 1;
    for (int i =0; i < n; i++)
    {
        if(students[i] == 0)
        {
            if(i == 0)
            {
                if(students[i + 1] == 2)
                {
                    students[i] += 1;
                    students[i + 1] -= 1;
                }
            }
            else if(i == n - 1)
            {
                if(students[i - 1] == 2)
                {
                    students[i] += 1;
                    students[i - 1] -= 1;
                }
            }
            else if(students[i-1] == 2)
            {
                students[i] += 1;
                students[i - 1] -= 1;
            }
            else if(students[i+1] == 2)
            {
                students[i] += 1;
                students[i + 1] -= 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (students[i] >= 1)
            answer++;
    return answer;
}
