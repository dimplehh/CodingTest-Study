#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findout(char goal) //좌표에 대한 vector(행, 열) 반환
{
    char key[4][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'} };

    vector<int> position;

    for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
    {
        for (int j = 0; j < sizeof(key[i]) / sizeof(char); j++)
        {
            if (key[i][j] == goal)
            {
                position.push_back(i);
                position.push_back(j);
                return position;
            }
        }
    }
}

char select(char l, char r, int goal)
{
    vector<int> g = findout(goal + '0'); //목표지점의 좌표
    vector<int> left = findout(l);
    vector<int> right = findout(r);

    int L = abs(g[0] - left[0]) + abs(g[1] - left[1]);
    int R = abs(g[0] - right[0]) + abs(g[1] - right[1]);

    if (L < R)
    {
        return 'L';
    }
    else if (L > R)
    {
        return 'R';
    }
    else
    {
        return 'S';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    char left = '*';
    char right = '#';

    for (int i = 0; i < numbers.size(); i++)
    {
        int n = numbers[i];
        if (n == 1 || n == 4 || n == 7) //왼쪽 키패드
        {
            answer += 'L';
            left = n + '0';
        }
        else if (n == 3 || n == 6 || n == 9) //오른쪽 키패드
        {
            answer += 'R';
            right = n + '0';
        }
        else //중앙 키패드
        {
            char s = select(left, right, n);
            if (s == 'L') //L이 가까우면 
            {
                answer += 'L';
                left = n + '0';
            }
            else if (s == 'R')//R이 가까우면
            {
                answer += 'R';
                right = n + '0';
            }
            else
            {
                if (hand.compare("left") == 0)
                {
                    answer += 'L';
                    left = n + '0';
                }
                else
                {
                    answer += 'R';
                    right = n + '0';
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> i = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string s = solution(i, "right");

    cout << s << endl;
}